import java.util.Scanner;
 
public class Main{
   static int arr[] = new int[4];
   public static void main(String[]args){
       Scanner sc = new Scanner(System.in);
       int students = sc.nextInt();
       int sx = sc.nextInt();
       int sy = sc.nextInt();
       for(int i = 0;i < students;i++){
            int x = sc.nextInt();
			int y = sc.nextInt();
			
			if(x <= sx && y <= sy){
			    if(x == sx) arr[3]++;
			    else if(y == sy) arr[0]++;
			    else{
			        arr[0]++;
                    arr[3]++;
			    }			   
			}else if(x <= sx && y >= sy){
			    if(x == sx) arr[1]++;
			    else if(y == sy) arr[0]++;
			    else{
			        arr[0]++;
                    arr[1]++;
			    }
			}else if(x >= sx && y >= sy){
			    if(x == sx) arr[1]++;
			    else if(y == sy) arr[2]++;
			    else{
			        arr[1]++;
                    arr[2]++;
			    }
			}else{
			    if(x == sx) arr[3]++;
			    else if(y == sy) arr[2]++;
			    else{
			        arr[2]++;
                    arr[3]++;
			    }
			}
       }
 
       int maxn = -1;
	   int dir = -1;
       for(int i = 0;i < 4;i++){
          if(maxn < arr[i]){
			 maxn = arr[i];
             dir = i;			 
		  }
       }		   
	   
	   if(dir == 0) sx--;
	   else if(dir == 1) sy++;
	   else if(dir == 2) sx++;
	   else sy--;
	   
	   
	   System.out.println(arr[dir]);
	   System.out.println(sx+" "+sy);
 
   }	   
	
}