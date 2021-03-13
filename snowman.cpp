//
// Created by eviat on 3/4/2021.
//

#include<iostream>
#include<stdexcept>
#include<string>
#include<array>
using namespace std;

const int H = 0; //hat
const int N= 1; //nose
const int LE = 2; //leftEye
const int RE = 3; //rightEye
const int LA=4; //leftArm
const int RA = 5; //rightArm
const int T = 6; //torso
const int B = 7; //base


array<string,4> Hat= {"_===_", "___\n.....", "_\n/_\\", "___\n(_*_)"};
array<string,4> Nose={",", ".","_"," "};
array<string,4> Eye={".", "o","O","-"};
array<string,4> LeftArm={"<","\\","/",""};
array<string,4> RightArm={">","/","\\",""};
array<string,4> Torso={" : ", "] [","> <","   "};
array<string,4> Base={" : ", "\" \"","___","   "};


namespace ariel {
    string snowman(int num) {

        //check the length of the input- can get exactly eight numbers
        const int validLength = 8;
        if (to_string(num).size() < validLength || to_string(num).size() > validLength) {
            throw out_of_range("it's can get only eight numbers!");
        }

        //check that it positive number
        if (num < 0) {
            throw out_of_range("the number must be positive!");
        }

        //check that all the eight numbers between 1-4
        const int divideNum = 10;
        int check_num = num;
        array<int,validLength> input = {0};
        for (int i = 0; i < validLength; i++) {
            int temp = check_num % divideNum;
            if (temp> 4 || temp < 1) {
                throw out_of_range("only numbers that between 1-4!");
            }
            input.at(validLength - i - 1) = check_num % divideNum;   //insert the numbers to array
            check_num = check_num / divideNum;
        }
        //if all the checks is valid run on the input and built the snowman
        string snowman;

                    //hat
                    snowman = "\n" + Hat.at(input.at(H)-1) + "\n";
                    //left up arm + nose + left eye + right eye
                    if (input.at(LA) == 2) {  //check if have up left arm
                        snowman += LeftArm.at(input.at(LA) - 1);
                    }
                    snowman += "(" + Eye.at(input.at(LE)-1) + Nose.at(input.at(N)-1) + Eye.at(input.at(RE)-1) + ")";
                    //right up arm
                    if (input.at(RA) == 2) {  //check if have up right arm
                        snowman += RightArm.at(input.at(RA)-1);
                    }
                    snowman += "\n";
                    //left arm, torso
                    if (input.at(LA) != 4 && input.at(LA) != 2) {  //check if have right arm
                        snowman += LeftArm.at(input.at(LA) - 1);
                    }
                    snowman += "(" + Torso.at(input.at(T)-1) + ")";
                    //right arm
                    if (input.at(RA) != 4 && input.at(RA) != 2) {  //check if have right arm
                        snowman += RightArm.at(input.at(RA) - 1);
                    }
                    snowman += "\n";
                    //base
                    snowman += "(" + Base.at(input.at(B)-1) + ")";


        return snowman;

    }
}