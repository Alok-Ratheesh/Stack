#include <iostream>
using namespace std;

//size of stack 
#define CAPAC 4
#define INVALID INT16_MAX   //error return 


class stack{
    private:
        int S[CAPAC];
        int topIndex; //only can declare in private + Index will always be an int type 

    public:
        //constructor and initialize topIndex inside constructor 
        stack(){
            topIndex = -1; //so that count can be topIndex + 1 even for empty case 
        } 
        int count(){
            return topIndex + 1;   
        }
        bool isEmpty(){
            if(count()==0) return true;
            else return false;
        }
        bool isFull(){
            if(count()==CAPAC) return true;
            else return false;
        }
       
        int pop(){
            if (isEmpty())  return INVALID; //stops the function here if stack is empty 
            int v = S[topIndex];    //top most elemet is to be poped yeah?
            topIndex --;    //bring the top 'pointer' down 
            return v;
        }

        bool push(int v){
            if (isFull())   return false;
            topIndex ++;    //first gotta go up in the pointer index 
            S[topIndex] = v;    //then modify the top element to v
            return true;
        }

        int peek(){
            if (isEmpty())  return INVALID;
            int v = S[topIndex];
            return v;   //don't change the topIndex cuz we don't modify the stack
        }
        void print(){
            int i;
            if (isEmpty()) {cout<<"Empty stack"; return;}

            cout<<"The Stack is given by : "<<endl;            
            cout<<"TOP -->";
            for (i=topIndex; i>=0; i--){
                cout<<"\t"<<S[i]<<"\n";
            }
        }
};


int main(){
    stack x;
    int y, o=1; // o to start the while loop
    cout<<"Welcome :D";
    while (o<8){
        cout<<"1.Push  2.Pop  3.Peek  4.Count  5.Empty?  6.Full?  7.Print 8.Exit "<<endl;
        cin>>o;
        switch(o){
            case 1:
                //push
                if (x.isFull()){
                    cout<<"Stack is Full -- Can't push an empty stack "<<endl;
                    break;
                }
                cout<<"Enter element to push ";
                cin>>y;
                x.push(y);
                break;
            case 2:     //pop
                if (x.isEmpty()){
                    cout<<"Stack is Empty -- Can't pop an empty stack "<<endl;
                }
                else{
                    y = x.pop();
                    cout<<"Poped element is "<<y<<endl;
                }
                break;
            case 3:     //peek
                if (x.isEmpty()){
                    cout<<"Stack is Empty"<<endl;
                }
                else{
                    y = x.peek();
                    cout<<"top element is "<<y<<endl;
                }
                break;
            case 4:     //count
                cout<<"The number of elemnts are "<<x.count()<<endl;
                break;
            case 5:     //empty?
                if(x.isEmpty())
                    cout<<"Yes, the Stack is Empty "<<endl;
                else
                    cout<<"No ";
                break;
            case 6:     //full?
                if(x.isFull())
                    cout<<"Yes, the Stack is Full "<<endl;
                else
                    cout<<"No "<<endl;
                break;
            case 7:
                x.print();
                break;
            case 8:
                cout<<"\n\nThank you!!";
                break;
            default: 
                cout<<"INVALID ENTRY ";
                break;
        }
    }

    return 314;
}
