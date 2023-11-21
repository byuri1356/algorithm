import java.util.*;

class Solution {
    public int solution(int[] order) {
        Stack<Integer> stack = new Stack<>();
        
        int answer = 0;
        int container = 1, pointer = 0;
   
        stack.push(0);
        
        while(pointer < order.length){
            if(container == order[pointer]){
                answer++; pointer++; container++;
            }
            else if(container < order[pointer]){
                stack.push(container);
                container++;
            }
            else{
                if(stack.pop() == order[pointer]){
                    answer++; pointer++;
                }
                else break;
            }
        }     
        
        return answer;
    }
}