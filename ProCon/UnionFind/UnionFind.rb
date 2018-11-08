class UnionFindTree
    def initialize(n)
        @tree = [*0...n]
    end
    def root(a)
        if @tree[a] == a
            return a
        end
        @tree[a] = root(@tree[a])
        return @tree[a]
    end
    def is_same_set(a, b)
        return root(a)==root(b)
    end
    def unite(a,b)
        @tree[root(a)] = root(b)
    end
    def printtree
        p @tree
    end
end

uft = UnionFindTree.new(10)
p uft.is_same_set(1,3)
uft.unite(1, 2)
p uft.is_same_set(1,3)
uft.unite(2, 3)
p uft.is_same_set(1,3)