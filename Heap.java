package TreePackage;

import java.util.List;

public class Heap {
    public static List<Float> insert(List<Float> elements , float val){
        elements.add(val);
        int index = elements.size() - 1;
        while(index > 1){
            if(elements.get(index) > elements.get(index / 2)){
                elements = swap(elements , index / 2 , index);
                index = index / 2;
            }else break;
        }
        return elements;
    }
    public static List<Float> swap(List<Float> element , int i , int j){
        float temp = element.get(i);
        element.set(i , element.get(j));
        element.set(j , temp);


        return element;
    }
    public static float popOut(List<Float> element){
        if(element.size() == 0 || element.size() == 1) return -1;
        float rootElement = element.get(1);
        element = swap(element , 1 , element.size() - 1);
        element.remove(element.get(element.size() - 1));
        int index = 1;
        while(index < element.size() - 1) {
            if (index * 2 < element.size() && (index * 2) + 1 < element.size()) {
                int grIndex = index * 2;
                if (element.get(index * 2) < element.get((index * 2) + 1)) {
                    grIndex = (index * 2) + 1;

                }
                if (element.get(index) < element.get(grIndex)) {
                    swap(element, index, grIndex);
                    index = grIndex;
                } else {
                    break;
                }
            } else if (index * 2 < element.size()) {
                if (element.get(index) < element.get(index * 2)) {
                    swap(element, index, 2 * index);
                    index = 2 * index;
                } else break;
            }
            else break;
        }

        return rootElement;
    }
}
