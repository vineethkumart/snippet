int find_tour(pump* p, int n)
{
	int start = 0;
	int end = 1;
	while (start != end || petrol < 0) {
		while (petrol < 0 && start != end) {
		petrol -= p[start].fuel();
		start = (start+1)%n;
		if (start == 0) return -1;
		}

		petrol += p[end].fuel();
		end = (end+1)%n;
	}
}
