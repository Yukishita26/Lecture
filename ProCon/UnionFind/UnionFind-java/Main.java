public class Main {
	public static void main(String[] args) {
        UnionFindTree uft = new UnionFindTree(10);
        System.out.println(uft.is_same_set(1, 3));
        uft.unite(1, 2);
        System.out.println(uft.is_same_set(1, 3));
        uft.unite(2, 3);
        System.out.println(uft.is_same_set(1, 3));
	}
}

class UnionFindTree{
    private int[] tree;
    UnionFindTree(int n){
        tree = new int[n];
        for(int i=0; i<n; i++) tree[i] = i;
    }
    int root(int a){
        if(tree[a] == a) return a;
        return (tree[a]=root(tree[a]));
    }
    boolean is_same_set(int a, int b){
        return tree[root(a)] == root(b);
    }
    void unite(int a, int b){
        tree[root(a)] = root(b);
    }
}