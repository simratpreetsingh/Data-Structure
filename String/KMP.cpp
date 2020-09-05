#include <iostream>
#include<vector>
using namespace std;
    
// tells if there is a suffix which is also prefix
// a b c a b y
// 0 0 0 1 2 0
 vector<int> calculateSuffixMatrix(string s){
        int n=s.size();
        vector<int> matrix(n,0);
        int i=1,j=0;
        while(i<n){
        if(s[i]==s[j]){
           matrix[i]=j+1;
            i++;
            j++;
        }
        else{
         if(j!=0){
             j=matrix[j-1];
         }
        else{
        i++;
        j=0;
        }
        }
        }
       return matrix;
    }

  bool KMP(string main,string pattern){
      int m=main.size(),n=pattern.size();
      vector<int> tempArray(n);
      tempArray=calculateSuffixMatrix(pattern);
      int i=0,j=0;
      while(i<m && j<n){
      if(main[i]==pattern[j]){
          i++;
          j++;
      }
      else{
       if(j!=0){
           j=tempArray[j-1];
       }
       else{
           i++;
       }
      }
      if(j==n){
          return true;
      }
      }
      return false;
  }

int main() {
    string main="abxabcabcaby",pattern="abcaby";
    cout<<KMP(main,pattern);
    return 0;
}
