/*
Distribute Concurrent key-value store
-------------------------------------

Functional Reqs:
1. put(key, value)
2. get(key, value)
3. Allow concurrent get and put

Non Functional
1. Highly concurrent
2. Scalable to millions of pairs
3. Highly Available, Reliable and FT, can compromise on consistency over availability may be. - or ask the design choice
    or may be tuneable consistency on setup



API
---
REST APIs
/api/put
input: key, string
       value, json encoded string of value

/api/get
input: key
output: value json encoded string

/api/find
input: pattern
output: value

/api/delete
input: key


Capacity Estimation
-------------------
100M DAU on an average each key-value may be 100kb
Total size requirement per day 100M * 100 Kb = 10TB per day
Total Capacity requirement for say 10 years:
10TB * 365 * 10 => 40PB

Traffic and Bandwidth Estimate:

ingress: 100M / 10^5 = 1000 entries per second => 100mbps
Assuming 1:100 read: 10gbps egress

Cache/Memory requirement: assuming 80-20 rule for the cache:
20% of the egress: 10gbps * 10^4 => 1000TB Cache/ Memory:

Shard the data into 10K shards -> 100GB cache per machine, its fine.

Concurrency:
-----------
each machine 100GB shard and lets use 1000 locks => 100MB sized chunk
and Each key can be hashed to one of these 100MB chunks and a lock to write to this chunk

R/W lock to support concurrent reads: Can use pthread_rw_lock for RW locks.


High Level Design
-----------------
Shard the data into multiple replica servers. N replica servers, keys and servers hashed into same key-space Consisitency Hashing
Each node has in memory memeTable (in memory key value store a hash table, dictionary)
Once the node is full, can flush to disk:

Models
1. Master slave model = talk about and tell the issues
2. Master Master model = talk about those both

Concurrency:
PUT(key, value) => CH, identify the shards to push the data into
Write to memTable  - Write through write back 
Write All/ Write Once - Write to all or none
    Bloom Filter to check if key is present in MemTable if so update the entry

Best could be Write to Quorum
Divide the replica sets into R read sets and W write sets st R + W > N, where N replica servers
can choose R and W accordingly to get trade off to read/write.

Once SSTable is full, write the SS table to disk.

SS Table = Sorted String Table
How to resolve Latest data
-------------------------
Uses versioning => W sets written and written with a version and when reading from R sets, get the data from all of R sets and return the latest version.
