#include <queue>

class MovingAverage {
public:
    /*
    * @param size: An integer
    */
    int size;
    queue<int> q, q2;
    double sum ;

    MovingAverage(int size) {
        // do intialization if necessary
        this->size = size;
        sum = 0;

    }


    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        // write your code here
        // Using Two stack approach
        // q.push(val);
        // q2.push(val);
        // for(int i=0; i<q.size(); i++){
        //     if(q2.size() > size){
        //        sum -= q2.front();
        //        q2.pop();
        //        sum += q.front();
        //        q.pop();
        //     }else{
        //       sum += q.front();
        //       q.pop();
        //     } 
          
        // }

        // return sum/q2.size();

    //--------------------------------------------------------------------------
    //Using 1 stack approach
        if(q.size() == size){
           sum -= q.front();
           q.pop();
        }

        q.push(val);
        sum += val;

        return sum/q.size();

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param = obj.next(val);
 */