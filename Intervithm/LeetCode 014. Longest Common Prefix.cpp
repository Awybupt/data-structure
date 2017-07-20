//Write a function to find the longest common prefix string amongst an array of strings.
class Solution   
{  
public:  
    string longestCommonPrefix(vector<string> &strs)   
    {  
        if(strs.size()==0) return "";  
        string result = strs[0];  
        int i = 1;  
        while(i<strs.size())  
        {  
            result = comprefix(result, strs[i]);  
            i++;  
        }  
        return result;  
    }  
  
    string comprefix(string a, string b)  
    {  
        string result;  
        int i=0, j=0;  
        while(i<a.length() && j<b.length() && a[i] == b[j])  
        {  
            i++;  
            j++;          
        }  
        result = a.substr(0,i);  
        return result;  
    }  
};  
