class Disjoint{
        int n;
        int[] parent;
        int[] rank;
        int[] size;
        public Disjoint(int n){
            this.n = n;
            parent = new int[n];
            rank = new int[n];
            size = new int[n];
            Arrays.fill(size , 1);
            for(int i = 0 ; i < n ; i++){
                parent[i] = i;
            }
        }
        public int find(int node){
            if(node != parent[node]){
                parent[node] = find(parent[node]);
            }
            return parent[node];
        }
        private void merge(int node1 , int node2){
            int p1 = find(node1);
            int p2 = find(node2);
            if(p1 == p2) return;
            if(rank[p1] > rank[p2]){
                parent[p2] = p1;
                rank[p2]++;
            }else{
                parent[p1] = p2;
                rank[p1]++;
            } 
        }
        private void mergeBySize(int node1 , int node2){
            int p1 = find(node1);
            int p2 = find(node2);
            if(p1 == p2) return;
            if(size[p1] > size[p2]){
                parent[p2] = p1;
                size[p1] += size[p2];
            }else{
                parent[p1] = p2;
                size[p2] += size[p1];
            }
        }
        private boolean isConnected(int node1 , int node2){
            return find(node1) == find(node2);
        }
    }
