# Used chatgpt to convert from cpp to python
# To observe the run time

class Item:
    def __init__(self):
        self.count = 0
        self.frequency = [0] * 45  # Adjust size according to your needs

class SegmentTree:
    def __init__(self):
        self.size = 0
        self.values = []
        self.NEUTRAL_ELEMENT = Item()

    def merge(self, a, b):
        c = Item()
        c.count = a.count + b.count

        for i in range(40, -1, -1):
            for j in range(i):
                c.count += a.frequency[i] * b.frequency[j]
            c.frequency[i] = a.frequency[i] + b.frequency[i]

        return c

    def single(self, v):
        it = Item()
        it.count = 0
        it.frequency[v] = 1
        return it

    def init(self, n):
        self.size = 1
        while self.size < n:
            self.size *= 2
        self.values = [self.NEUTRAL_ELEMENT] * (self.size * 2)

    def build(self, a, x, lx, rx):
        if rx - lx == 1:
            if lx < len(a):
                self.values[x] = self.single(a[lx])
            return

        mid = lx + (rx - lx) // 2
        self.build(a, 2 * x + 1, lx, mid)
        self.build(a, 2 * x + 2, mid, rx)
        self.values[x] = self.merge(self.values[2 * x + 1], self.values[2 * x + 2])

    def build_full(self, a):
        self.init(len(a))
        self.build(a, 0, 0, self.size)

    def set(self, i, v, x, lx, rx):
        if rx - lx == 1:
            self.values[x] = self.single(v)
            return

        mid = lx + (rx - lx) // 2
        if i < mid:
            self.set(i, v, 2 * x + 1, lx, mid)
        else:
            self.set(i, v, 2 * x + 2, mid, rx)

        self.values[x] = self.merge(self.values[2 * x + 1], self.values[2 * x + 2])

    def set_full(self, i, v):
        self.set(i, v, 0, 0, self.size)

    def calculate(self, l, r, x, lx, rx):
        if lx >= r or rx <= l:
            return self.NEUTRAL_ELEMENT
        elif lx >= l and rx <= r:
            return self.values[x]
        else:
            mid = lx + (rx - lx) // 2
            it1 = self.calculate(l, r, 2 * x + 1, lx, mid)
            it2 = self.calculate(l, r, 2 * x + 2, mid, rx)
            return self.merge(it1, it2)

    def calculate_full(self, l, r):
        return self.calculate(l, r, 0, 0, self.size)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    m = int(data[1])
    v = list(map(int, data[2:n + 2]))

    st = SegmentTree()
    st.build_full(v)

    index = n + 2
    results = []

    for _ in range(m):
        op = int(data[index])
        if op == 2:
            x = int(data[index + 1]) - 1
            y = int(data[index + 2])
            st.set_full(x, y)
            index += 3
        else:
            x = int(data[index + 1]) - 1
            y = int(data[index + 2])
            it = st.calculate_full(x, y)
            results.append(it.count)
            index += 3

    sys.stdout.write("\n".join(map(str, results)) + "\n")

if __name__ == "__main__":
    main()
