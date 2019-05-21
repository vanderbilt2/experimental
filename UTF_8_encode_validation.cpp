
// solution-1:  not pass.
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        int i = 0;
        while(i<data.size()){
            int val = data[i];
            if(count == 0){
                if((val & (240) == 240) && (val & 8 == 0))
                    count = 3;
                else if((val & 224 == 224) && (val & 32 == 0))
                    count = 2;
                else if((val & 192 == 192) && (val & 64 == 0)){
                    count = 1;
                }
                else if((val & 127 == 127))
                {
                    count = 0;
                }
                else
                    return false;
            }
            else{
                if((val & 128 == 128) & (val & 192 == 128)){
                    count--;
                }
                else{
                    return false;
                }
            }
            i++;            
        }
        return (count == 0);
    }
};
