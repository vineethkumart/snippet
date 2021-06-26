/*
Publisher Subscriber Pattern
----------------------------
Refer: https://en.wikipedia.org/wiki/Publish%E2%80%93subscribe_pattern
Req:
Multiple Processes want to send Messages to multiple other processes. Could be 1-1 or 1-group etc.,

Key Points
----------
1. Provides loose coupling by decoupling sender and receiver from each other through a mediator(Broker Process)
2. Sender Keeps sending messages to the Broker Process intended to be sent to Pj.
3. Receivers register a Callback to receive the message on arrival.
4. BP is responsbile for delivery, ACK, Retry, etc,
5. This can be decoupled again by not even knowing which Pj is interested on the message. Pi just genertes messages of specific category(type)
and sends BP. Pj will register a callback for receiving interested messages.


Publish–subscribe is a sibling of the message queue paradigm, and is typically one part of a larger message-oriented middleware system. Most messaging systems support both the pub/sub and message queue models in their API; e.g., Java Message Service (JMS).

Topic Based         - interested on sepcific topic(type)
Content Based       - Subscriber defines constraints to match content

Broker Process
--------------
1. Store and Forward()  - Reliability
2. Redundancy and Backup BP - Availability
3. BP can marshal/demarshal/transform etc., the message
4. BP can prioritize the message, handle failures


Issues
------
1. If you need guaranted delivery/ tighter coupling
2. SpoF - handle by redundancy and backup server/process
3. High Load and bottleneck - need LB and multiple servers
4. Security. Broker can be fooled into sending many messages to subscribers DoS
*/
enum msg_type_t {
    msg1,
    msg2
};

// Library Code
class MsgLibrary {
public:
    MsgLibrary() {
        // check if broker process exist
        // if not create one
        bp = new BrokerProcess();

    }
    void Subscribe(Process* p, vector<msg_type_t>& topics) {
        subs[topic].push_back(p);
    }

    void send(Message* msg) {
        // push to queue
        mq.push(msg);

        // Ask the broker process to send message to all subscribers

        q.pop(); // message sent successfully.
    }
private:
    BrokerProcess* bp;
    map<topic, vector<process*>> subs;
    queue<Message*> mq;
};

class Message {
public:
    get_type();
    get_content();
private:
    msg_type_t type;
    msg_content_t content;
};

class Process {
public:
    virtual void process(const Message& msg) = 0;
};


// Client Code
class Application : Process {
public:
    void init() {
        l  = new MsgLibrary(/*params*/);
        vector<msg_type_t> topics;
        l->Subscribe(this, topics);
    }

    void Send(Message msg) {
        l->send(msg);
    }

    void process(const Message& msg) {
        if (msg.type() == 'my_interested_type') {
            // Process and accept message

        }
    }
private:
    MsgLibrary* l;
};



