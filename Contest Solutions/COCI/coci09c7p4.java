import java.io.*;
import java.util.*;

public class Main {
    static int[] id;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Point> pqx = new PriorityQueue<Point>(n, (a, b) -> a.c - b.c), pqy = new PriorityQueue<Point>(n, (a, b) -> a.c - b.c), pqz = new PriorityQueue<Point>(n, (a, b) -> a.c - b.c);
        id = new int[n];
        ArrayList<Edge> edges = new ArrayList<Edge>();
        long c = 0;
        
        for (int i = 0; i < n; i++) {
            id[i] = -1;
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), z = Integer.parseInt(st.nextToken());
            pqx.offer(new Point(i, x));
            pqy.offer(new Point(i, y));
            pqz.offer(new Point(i, z));
        }
        for (int i = 1; i < n; i++) {
            Point px = pqx.poll(), cx = pqx.peek(), py = pqy.poll(), cy = pqy.peek(), pz = pqz.poll(), cz = pqz.peek();
            edges.add(new Edge(px.i, cx.i, cx.c - px.c));
            edges.add(new Edge(py.i, cy.i, cy.c - py.c));
            edges.add(new Edge(pz.i, cz.i, cz.c - pz.c));
        }
        
        Collections.sort(edges, (a, b) -> a.c - b.c);
        
        for (Edge e : edges) {
            if (find(e.a) != find(e.b)) {
                c += e.c;
                union(e.a, e.b);
            }
        }
        
        System.out.println(c);
    }
    public static int find(int x) {
        return id[x] < 0 ? x : (id[x] = find(id[x]));
    }
    public static void union(int x, int y) {
        if (id[x = find(x)] < id[y = find(y)]) {
            id[x] += id[y];
            id[y] = x;
        }
        else {
            id[y] += id[x];
            id[x] = y;
        }
    }
}

class Point {
    int i, c;
    public Point(int i, int c) {
        this.i = i;
        this.c = c;
    }
}

class Edge {
    int a, b, c;
    public Edge(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}
