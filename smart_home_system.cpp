#include <bits/stdc++.h>
using namespace std;
class device
{
protected:
    string name;
    bool status = false;

public:
    static int devices;
    void setName(string n)
    {
        name = n;
    }
    virtual void changeCondition()
    {
        status = !status;
    }
    bool currentStatus()
    {
        return status;
    }
    string getName()
    {
        return name;
    }
};
int device::devices = 0;
class fan : public device
{
    int speed = 0;

public:
    fan()
    {
        devices++;
    }
    void changeSpeed(int n)
    {
        speed = n;
    }
    int currentSpeed()
    {
        return speed;
    }
};
class light : public device
{
public:
    light()
    {
        devices++;
    }
};
class airconditioner : public device
{
    int temp = 24;

public:
    airconditioner()
    {
        devices++;
    }
    void setTemp(int t)
    {
        temp = t;
    }
    int currentTemp()
    {
        return temp;
    }
};
class smartlock : public device
{
    int pin = 1234;

public:
    smartlock()
    {
        devices++;
    }
    void setpin(int n)
    {
        pin = n;
    }
    void changeCondition(int n)
    {
        if (n == pin)
            status = !status;
        else
            cout << "Wrong Pin, Try Again!!!" << endl;
    }
    void changeCondition()
    {
        status = !status;
    }
    int getPin()
    {
        return pin;
    }
};
int main()
{
    vector<fan> fans;
    vector<light> lights;
    vector<airconditioner> acs;
    vector<smartlock> locks;
    cout << setw(500) << "--- WELCOME TO SMART HOME ---" << endl;
    while (1)
    {
        cout << "\nTotal devices: " << device::devices << endl;
        cout << "1. Control Devices" << endl;
        cout << "2. Add Device" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            if (device::devices == 0)
            {
                cout << "There isn't any device to control... Please add it first.\n";
                break;
            }
            cout << "\nControl which device?\n";
            cout << "1. Fan\n2. Light\n3. Air Conditioner\n4. Smart Lock\n";
            int ch;
            cin >> ch;
            if (ch == 1 && !fans.empty())
            {
                cout << "1. Turn ON/OFF and change speed\n2. Check current speed\n";
                int opt;
                cin >> opt;
                if (opt == 1)
                {
                    int i;
                    cout << "Enter fan index (0 - " << fans.size() - 1 << "): ";
                    cin >> i;
                    if (i >= 0 && i < fans.size())
                    {
                        fans[i].changeCondition();
                        cout << "Fan turned " << (fans[i].currentStatus() ? "ON" : "OFF") << endl;
                        if (fans[i].currentStatus())
                        {
                            int s = 0;
                            while (s < 1 || s > 5)
                            {
                                cout << "Enter speed between 1 to 5: ";
                                cin >> s;
                                if (s < 1 || s > 5)
                                {
                                    cout << "Enter the valid speed!!!" << endl;
                                }
                            }
                            fans[i].changeSpeed(s);
                            cout << "Current speed: " << fans[i].currentSpeed() << endl;
                        }
                    }
                    else
                        cout << "Invalid fan index.\n";
                }
                else if (opt == 2)
                {
                    int i;
                    cout << "Enter fan index (0 - " << fans.size() - 1 << "): ";
                    cin >> i;
                    if (i >= 0 && i < fans.size())
                    {
                        if (fans[i].currentStatus())
                            cout << "Current fan speed: " << fans[i].currentSpeed() << endl;
                        else
                            cout << "Fan is currently OFF, please turn it ON first!" << endl;
                    }
                    else
                        cout << "Invalid fan index.\n";
                }
                else
                    cout << "Invalid option.\n";
            }
            else if (ch == 2 && !lights.empty())
            {
                int i;
                cout << "Enter light index (0 - " << lights.size() - 1 << "): ";
                cin >> i;
                if (i >= 0 && i < lights.size())
                {
                    lights[i].changeCondition();
                    cout << "Light turned " << (lights[i].currentStatus() ? "ON" : "OFF") << endl;
                }
                else
                    cout << "Invalid light index.\n";
            }
            else if (ch == 3 && !acs.empty())
            {
                cout << "1. Turn ON/OFF and change temperature\n2. Check current temperature\n";
                int opt;
                cin >> opt;
                if (opt == 1)
                {
                    int i;
                    cout << "Enter AC index (0 - " << acs.size() - 1 << "): ";
                    cin >> i;
                    if (i >= 0 && i < acs.size())
                    {
                        acs[i].changeCondition();
                        cout << "AC turned " << (acs[i].currentStatus() ? "ON" : "OFF") << endl;
                        if (acs[i].currentStatus())
                        {
                            int t = 0;
                            while (t < 16 || t > 30)
                            {
                                cout << "Enter new temperature between 16 to 30: ";
                                cin >> t;
                                if (t < 16 || t > 30)
                                {
                                    cout << "Enter the valid temperature!!!" << endl;
                                }
                            }
                            acs[i].setTemp(t);
                            cout << "Temperature set to " << acs[i].currentTemp() << "\n";
                        }
                    }
                    else
                        cout << "Invalid AC index.\n";
                }
                else if (opt == 2)
                {
                    int i;
                    cout << "Enter AC index (0 - " << acs.size() - 1 << "): ";
                    cin >> i;
                    if (i >= 0 && i < acs.size())
                    {
                        if (acs[i].currentStatus())
                            cout << "Current AC temperature: " << acs[i].currentTemp() << "°C\n";
                        else
                            cout << "AC is currently OFF, please turn it ON first!" << endl;
                    }
                    else
                        cout << "Invalid AC index.\n";
                }
                else
                    cout << "Invalid option.\n";
            }
            else if (ch == 4 && !locks.empty())
            {
                cout << "1. Lock/Unlock\n2. Change PIN\n";
                int opt;
                cin >> opt;
                if (opt == 1)
                {
                    int i;
                    cout << "Enter lock index (0 - " << locks.size() - 1 << "): ";
                    cin >> i;
                    if (i >= 0 && i < locks.size())
                    {
                        if (locks[i].currentStatus())
                        {
                            cout << "Lock is currently OPEN.\n";
                            cout << "Do you want to close it? (y/n): ";
                            char c;
                            cin >> c;
                            if (c == 'y' || c == 'Y')
                            {
                                locks[i].changeCondition();
                                cout << "Lock is now CLOSED.\n";
                            }
                            else
                            {
                                cout << "Lock remains OPEN.\n";
                            }
                        }
                        else
                        {
                            int p;
                            cout << "Enter pin to open: ";
                            cin >> p;
                            locks[i].changeCondition(p);
                            if (locks[i].currentStatus())
                                cout << "Lock is now OPENED.\n";
                            else
                                cout << "Lock remains CLOSED.\n";
                        }
                    }
                    else
                        cout << "Invalid lock index.\n";
                }
                else if (opt == 2)
                {
                    int i;
                    cout << "Enter lock index (0 - " << locks.size() - 1 << "): ";
                    cin >> i;
                    if (i >= 0 && i < locks.size())
                    {
                        int oldPin, newPin;
                        cout << "Enter old pin: ";
                        cin >> oldPin;
                        if (oldPin == locks[i].getPin())
                        {
                            cout << "Enter new pin: ";
                            cin >> newPin;
                            locks[i].setpin(newPin);
                            cout << "Pin changed successfully!\n";
                        }
                        else
                        {
                            cout << "Incorrect old pin! Pin not changed.\n";
                        }
                    }
                    else
                        cout << "Invalid lock index.\n";
                }
                else
                    cout << "Invalid option.\n";
            }
            else
            {
                cout << "No such device type added yet.\n";
            }
            break;
        }
        case 2:
        {
            cout << "\nAdd which device?\n";
            cout << "1. Fan\n2. Light\n3. Air Conditioner\n4. Smart Lock\n";
            int type;
            cin >> type;
            if (type == 1)
            {
                fan f;
                fans.push_back(f);
                cout << "Fan added successfully.\n";
            }
            else if (type == 2)
            {
                light l;
                lights.push_back(l);
                cout << "Light added successfully.\n";
            }
            else if (type == 3)
            {
                airconditioner a;
                acs.push_back(a);
                cout << "Air Conditioner added successfully.\n";
            }
            else if (type == 4)
            {
                smartlock s;
                locks.push_back(s);
                cout << "Smart Lock added successfully.\n";
            }
            else
            {
                cout << "Invalid option.\n";
            }
            break;
        }
        case 3:
            cout << setw(495) << "--- Exiting Smart Home. Goodbye! ---\n";
            return 0;
        default:
            cout << "Invalid input! Try again.\n";
        }
    }
}