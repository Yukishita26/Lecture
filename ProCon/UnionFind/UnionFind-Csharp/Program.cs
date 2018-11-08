using System;

namespace UnionFind_Csharp{
    class Program{
        static void Main(string[] args){
            var uft = new UnionFindTree(10);
            Console.WriteLine(uft.is_same_set(1, 3));
            uft.unite(1, 2);
            Console.WriteLine(uft.is_same_set(1, 3));
            uft.unite(2, 3);
            Console.WriteLine(uft.is_same_set(1, 3));
        }
    }
    
    class UnionFindTree{
        private int[] tree;
        public UnionFindTree(int n){
            tree = new int[n];
            for(int i=0; i<n; i++) tree[i] = i;
        }
        public int root(int a){
            if(tree[a] == a) return a;
            return (tree[a]=root(tree[a]));
        }
        public bool is_same_set(int a, int b) => tree[root(a)] == root(b);
        public void unite(int a, int b)=> tree[root(a)] = root(b);
    }
}
