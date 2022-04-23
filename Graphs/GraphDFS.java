/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class GraphDFS {
	public static void main(String[] args){
	    Scanner scanner = new Scanner(System.in);
	    int vertex = scanner.nextInt();vertex++;
	    int edges = scanner.nextInt();
	    ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0 ; i < vertex ; i++){
            adj.add(new ArrayList<>());
        }
	    for(int i = 0 ; i < edges ; i++){
	        System.out.println("Enter Source -> ");
	        int source = scanner.nextInt();
	        System.out.println("Enter Destination -> ");
	        int dest = scanner.nextInt();
	        add(adj , source , dest);
	    }
	    System.out.println("Enter Init Vertex - ");
	    int init = scanner.nextInt();
	    System.out.println("Enter Final Destination Vertex");
	    int target = scanner.nextInt();
	    if(init >= vertex || target >= vertex){
	        System.out.println("Invalid Input");
	    }else{
	        Queue<Integer> queue = new LinkedList<>();
	        boolean[] isVisited = new boolean[vertex + 1];
	        queue.offer(init);
	        isVisited[init] = true;
	        while(!queue.isEmpty()){
	            int curVex = queue.poll();
	            for(int ele : adj.get(curVex)){
	                if(!isVisited[ele]){
	                    queue.offer(ele);
	                    isVisited[ele] = true;
	                    if(ele == target) {
	                        System.out.println("Element Found");
	                        break;
	                    }
	                }
	            }
	        }
	    }
	}
	private static void  add(ArrayList<ArrayList<Integer>> adj , int source , int dest){
	    adj.get(source).add(dest);
	    adj.get(dest).add(source);
	}
}
