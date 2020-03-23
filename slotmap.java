import java.util.*;

class comp implements Comparator<Pair>{
    public int compare(Pair x, Pair y) {
        return x.a-y.b;
    }
}
class Pair{
    int a,b;
    Pair(int x,int y){
        a=x;
        b=y;
    }
}
class SlotMap{
    TreeMap<String,Pair> hm; 
    SlotMap(){
        hm=new TreeMap<String,Pair>();    
    }
    public void set(int a,int b,String v){
            Iterator<String> itr = hm.keySet().iterator();
            while(itr.hasNext()){
                
                String str=itr.next();
                Pair temp=hm.get(str); 
                if(temp.a<b){
                    hm.put(str,new Pair(b,temp.b));
                }    
            }
           
            Pair add=new Pair(a,b);
            hm.put(v,add);
        
    }
    public void display(){
        for(String str:hm.keySet()){
            Pair temp=hm.get(str); 
            System.out.println(temp.a+" "+temp.b+" "+str);
        }   
    }
}
public class slotmap
{
	public static void main(String[] args) {
		SlotMap sm=new SlotMap();
		sm.set(3,8,"one");
		sm.set(2,5,"two");
		sm.set(4,7,"three");
		sm.display();
	}
}