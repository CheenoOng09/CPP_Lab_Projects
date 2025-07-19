#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double myHeight;
    double myWeight;
    double myBMI;
    bool testing = true;


    while (testing)
    {
        a:
        cout << "Input weight (kg): ";
        cin >> myWeight;
        cout << "Input height (m): ";
        cin >> myHeight;

        if (myWeight <= 20 || myWeight >= 200){
            cout << "#Invalid weight (>= 20kg and <= 200kg)" << endl;
            goto a;
        }
        else if (myHeight <= 0.9 || myHeight >= 2.5){
            cout <<"#Invalid height (>= 0.9m and <= 2.5m)" << endl;
            goto a;
        }
        myBMI = round(myWeight/(myHeight*myHeight)*10)/10.0;
        cout << "# Your weight(kg): " << myWeight << endl;
        cout << "# Your height(m): " << myHeight << endl;
        cout << "# Your BMI: " << myBMI << endl;

        if (myBMI < 10){
            cout << "# You BMI level is unreasonably small" << endl;
            cout << "# Either weight or height might be wrongly given (Step 4)." << endl;
            cout << "# If weight given is correct, then the given height should be at most " << sqrt(myWeight / 10) << "m (Step 4)." << endl;
            cout << "# If height given is correct, then the given weight should be at least " << 10 * (myHeight*myHeight) << "kg (Step 4)." << endl;
        }
        else if (myBMI >= 10 && myBMI <= 15){
            cout << "# Your BMI level is highly severely underweight" << endl;
            cout << "# Increase your weight to " << 18.5 * (myHeight*myHeight) << " kg to bring your BMI value to 18.5 (Step 5)." << endl;
        }
        else if (myBMI > 15 && myBMI <= 16){
            cout << "# Your BMI level is severely underweight" << endl;
            cout << "# Increase your weight to " << 18.5 * (myHeight*myHeight) << " kg to bring your BMI value to 18.5 (Step 5)" << endl;
        }
        else if (myBMI > 16 && myBMI < 18.5){
            cout << "# Your BMI level is underweight" << endl;
            cout << "# Increase your weight to " << 18.5 * (myHeight*myHeight) << " kg to bring your BMI value to 18.5 (Step 5)." << endl;
        }
        else if (myBMI >= 18.5 && myBMI <= 25){
            cout << "# Your BMI level is normal" << endl;
        }
        else if (myBMI > 25 && myBMI <= 40){
            cout << "# Your BMI level is overweight" << endl;
            cout << "# Decrease your weight to " << 25 * (myHeight*myHeight) << " kg to bring your BMI value to 25 (Step 5)." << endl;
        }
        else if (myBMI > 40 && myBMI <= 50){
            cout << "# Your BMI level is obese" << endl;
            cout << "# Decrease your weight to " << 25 * (myHeight*myHeight) << " kg to bring your BMI value to 25 (Step 5)." << endl;
        }
        else if (myBMI > 50 && myBMI <= 60){
            cout << "# Your BMI level is severely obese" << endl;
            cout << "# Decrease your weight to " << 25 * (myHeight*myHeight) << " kg to bring your BMI value to 25 (Step 5)." << endl;
        }
        else if (myBMI > 60 && myBMI <= 70){
            cout << "# Your BMI level is highly severely obese" << endl;
            cout << "# Decrease your weight to " << 25 * (myHeight*myHeight) << " kg to bring your BMI value to 25 (Step 5)." << endl;
        }
        else if (myBMI > 70 ){
            cout << "# You BMI level is unreasonably large" << endl;
            cout << "# Either weight or height might be wrongly given (Step 4)." << endl;
            cout << "# If weight given is correct, then the given height should be at most " << sqrt(myWeight / 70) << "m (Step 4)." << endl;
            cout << "# If height given is correct, then the given weight should be at least " << 70 * (myHeight*myHeight) << "kg (Step 4)." << endl;
        }
    }
    return 0;
}
