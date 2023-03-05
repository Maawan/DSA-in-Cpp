class Disjoint{
        int n;
        int[] parent;
        int[] rank;
        public Disjoint(int n){
            this.n = n + 1;
            n = this.n;
            parent = new int[n];
            for(int i = 0 ; i < n ; i++){
                parent[i] = i;
            }
            rank = new int[n];
        }
        public int find(int node){
            if(parent[node] != node){
                parent[node] = find(parent[node]);
            }
            return parent[node];
        }
        public void merge(int node1 , int node2){
            int p1 = find(node1);
            int p2 = find(node2);
            if(p1 == p2) return;
            if(rank[p1] > rank[p2]){
                parent[p2] = p1;
                rank[p1]++;
            }else{
                parent[p1] = p2;
                rank[p2]++;
            }
        }
        public boolean isSame(int node1 , int node2){
            return find(node1) == find(node2);
        }
    }
