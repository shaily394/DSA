class Solution {
public:
    string intToRoman(int num) {
                vector<pair<int, string>> roman_letters = {{1000 , "M"  } , {900 , "CM"} , {500 , "D"} , { 400 , "CD" } , { 100 , "C"  } , { 90, "XC" },{50 , "L" } , {40 , "XL" } , {10 ,  "X" } , {9 , "IX" } , {5 ,  "V" } , {4  , "IV"} , {1,  "I"} };
             // descending order

            string roman ="";
            int i =0;
            while( num != 0){
                if(num >= roman_letters[i].first){
                    num -= roman_letters[i].first;
                    roman += roman_letters[i].second;
                }
                else i++;
            }
            return roman;
}
};