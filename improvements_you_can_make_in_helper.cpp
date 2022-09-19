class UFDS
{
private:
	vi parent, size, dist;
public:
	UFDS(vi newDist) {
		int newSize = newDist.size();
		dist = newDist;
		parent.resize(newSize);
		for (int i = 0; i < newSize; i++) {
			parent[i] = i;
		}
		size.assign(newSize, 1);
	}

	int find(int x) {
		if (x == parent[x]) {
			return x;
		}
		parent[x] = find(parent[x]);
		return parent[x];
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	void join(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (size[x] < size[y]) swap(x, y);
		parent[y] = x;
		size[x] += size[y];
		dist[x] = dist[y] = min(dist[x], dist[y]);
	}

	int getDist(int x) {
		return dist[find(x)];
	}
};
