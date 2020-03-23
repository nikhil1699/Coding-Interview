import java.util.*;

class SlotMap<T>{
    private TreeMap<Integer, Integer> t;
    private Map<T, Integer> m;

    SlotMap(){
        t = new TreeMap<>();
        m = new HashMap<>();
    }

    private void rangeSort(TreeMap<Integer, Integer> t) {
        TreeMap<Integer, Integer> st = new TreeMap<>();
        Set set = t.entrySet();
        Iterator it = set.iterator();
        Map.Entry entry = (Map.Entry)it.next();
        int k = (int) entry.getKey();
        int v = (int) entry.getValue();
        st.put(k, v);
        while (it.hasNext()){
            entry = (Map.Entry)it.next();
            int kn = (int) entry.getKey();
            int vn = (int) entry.getValue();
            st.put(Math.max(v, kn), vn);
            k = kn;
            v = vn;
        }
        t.clear();
        t.putAll(st);
    }

    void set(int l, int r, T val) {
        t.put(l,r);
        m.put(val, r);
        rangeSort(t);
    }

    void display() {
        t.forEach((l, r) -> {
            for(Map.Entry<T, Integer> entry: m.entrySet()){
                if(r.equals(entry.getValue())){
                    System.out.println(l + " " + r + " " + entry.getKey());
                }
            }
        });
    }
}


public class MyClass
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        SlotMap<String> sm = new SlotMap<>();
        int n = s.nextInt();
        while(n > 0) {
            int l = s.nextInt();
            int r = s.nextInt();
            s.nextLine();
            String v = s.nextLine();
            n--;
            sm.set(l, r, v);
        }
        sm.display();
    }
}