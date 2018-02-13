import java.util.*;

public class Main {
    public static void main(String[] args) {
       Scanner in =new Scanner(System.in);
       int n=in.nextInt();
       String s=in.next();
       int ar []=new int[200]; for(int i=0;i<200;i++) ar[i]=0;
       int j=0;
       int res=999999999;
       int total=0;
       for(int i=0;i<s.length();i++){
           if(ar[s.charAt(i)]==0) total++;
           ar[s.charAt(i)]=1;
         }
       
       for(int i=0;i<200;i++) ar[i]=0;
       int temp=0;
        for(int i=0;i<s.length();i++){
           if(ar[s.charAt(i)]==0) temp++;
           ar[s.charAt(i)]++;
           int flag=0;
           while(temp>=total){
                flag=1;
               if(ar[s.charAt(j)]==1)
                   temp--;
                  ar[s.charAt(j)]--;
                  j++;
               }
            if(flag==1){
                j--;
                   temp++;
                    ar[s.charAt(j)]++;
               }
          // System.out.println(total);
           if(temp==total) res=Math.min(res, i-j+1);
         }
        System.out.println(res);
    }
    
}