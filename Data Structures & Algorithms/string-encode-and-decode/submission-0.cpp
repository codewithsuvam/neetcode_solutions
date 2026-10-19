//algo for this codee in just 6 lines for implement 
// 1. For each string, append its length, a delimiter '#', and the string itself.
// 2. Concatenate all encoded parts into one string and return it.
// 3. During decoding, find the delimiter to read the next string's length.
// 4. Convert the length to an integer and extract exactly that many characters.
// 5. Add the extracted string to the result and move the index to the next encoded part.
// 6. Repeat until the entire encoded string is processed, then return the result.
//here is the code 
class Solution{
    public:
    string encode(vector<string>& strs){
        string result ="";
        for(string s: strs){
            result += to_string(s.size())+ "#"+s;
        }
        return result;
    }
    vector<string> decode(string s){

    vector<string>result;
    int i = 0;
    while(i<s.size()){
        int j = i;
        //here we write for find the delimiter 
        while (s[j]!='#'){
            j++;
        }
        int len=stoi(s.substr(i,j-i));
        string word=s.substr(j+1,len);
        result.push_back(word);
        i= j +1+ len;
    }
return result;
}
};