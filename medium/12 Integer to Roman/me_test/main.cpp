class Solution {
public:
    string intToRoman(int num) {
        string k;
        while(num != 0){
            if(num >= 1000){
                k += "M";
                num -= 1000;
            }
            else if(num >= 900){
                k += "CM";   
                num -= 900;
            }
            else if(num >= 500){
                k += "D";
                num -= 500;
            }
            else if(num >= 400){
                k += "CD";   
                num -= 400;
            }
            else if(num >= 100){
                k += "C";
                num -= 100;
            }
            else if(num >= 90){
                k += "XC";
                num -= 90;
            }
            else if(num >= 50){
                k += "L";
                num -= 50;
            }
            else if(num >= 40){
                k += "XL";
                num -= 40;
            }
            else if(num >= 10){
                k += "X";
                num -= 10;
            }
            else if(num >= 9){
                k += "IX";
                num -= 9;
            }
            else if(num >= 5){
                k += "V";
                num -= 5;
            }
            else if(num >= 4){
                k += "IV";
                num -= 4;
            }
            else{
                k += "I";
                num -= 1;
            }
        }
        return k;
    }
};