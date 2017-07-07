
package dijkstra;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class Dijkstra {

public static void main(String[] args) throws FileNotFoundException, IOException {

//22个基站数据
        double [][] a = new double [23][23];//存22基站距离
        double [] dist = new double [23];//与567443的距离
        int [] prev = new int [23];//最短距离前一个节点
        int [] node = new int [23];//基站号
//42个基站数据
        double [][] a1=new double [43][43];
        double [] dist1 = new double [43];
        int [] prev1 = new int [43];
        int [] node1 = new int [43];



        RandomAccessFile file = new RandomAccessFile("djstra.txt","r");  //读取22基站数据
        String str;
        for(int i=1;i<23;++i)
            for(int j=1;j<23;++j){
                str=file.readLine();
                double d=Double.parseDouble(str);
                if(d==-1)  a[i][j]=Double.MAX_VALUE;
                else  a[i][j]=d;
            }
        for(int i=1;i<23;++i){
            str=file.readLine();  node[i]=Integer.parseInt(str);
        }
        file.close();
        RandomAccessFile file1 = new RandomAccessFile("2.txt","r");//读取42基站数据
        for(int i=1;i<43;++i)
            for(int j=1;j<43;++j){
                str=file1.readLine();
                double d=Double.parseDouble(str);
                if(d==-1) a1[i][j]=Double.MAX_VALUE;
                else a1[i][j]=d;
            }
        for(int i=1;i<43;++i){
            str=file1.readLine();
            node1[i]=Integer.parseInt(str);
        }
        file1.close();
        dijkstra(20,a,dist,prev);
        for(int i=1;i<23;++i)
            System.out.println(i+". 567443到点"+node[i]+"的最短距离："+dist[i]);
        System.out.println();
        dijkstra(16,a1,dist1,prev1);
        for(int i=1;i<43;++i)
            System.out.println(i+". 565845到点"+node1[i]+"的最短距离："+dist1[i]);
}





    public static void dijkstra(int v,double [][]a,double []dist,int []prev){
        int n=dist.length-1;
        if(v<1||v>n) return;
        boolean []s=new boolean[n+1];
        for(int i=1;i<=n;++i){          //初始化s
            dist[i]=a[v][i]  s[i]=false;
            if(dist[i]==Double.MAX_VALUE) prev[i]=0;
            else prev[i]=v;
        }
        dist[v]=0;s[v]=true;
        for(int i=1;i<n;++i){
            double temp=Double.MAX_VALUE;  int u=v;
            for(int j=1;j<=n;++j)
                if((!s[j])&&(dist[j])<temp){
                    u=j;  temp=dist[j];
                }   s[u]=true;
            for(int j=1;j<=n;++j)
                if((!s[j])&&(a[u][j]<Double.MAX_VALUE)){
                    double newdist = dist[u]+a[u][j];
                    if(newdist<dist[j]){
                        dist[j]=newdist;   prev[j]=u;
                    }
                }
        }
    }
}

