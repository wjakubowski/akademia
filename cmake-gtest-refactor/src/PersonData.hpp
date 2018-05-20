#pragma once

#include <string>
#include <cctype>

class PersonData {
    std::string name_;
    std::string surname_;
    std::string pesel_;
    int age_;

    bool valid = true;
public:
    PersonData(const std::string& name, const std::string& surname,
            const std::string& pesel, int age)
        : name_{name}, surname_{surname}, pesel_{pesel}, age_{age}
    {
        valid = checkPesel();
    }

    const std::string& name() const { return name_; }
    const std::string& surname() const { return surname_; }
    const std::string& pesel() const { return pesel_; }
    int age() const { return age_; }

    bool isValid() const { return valid; }
private:
    bool checkPesel() {
        if (pesel_.length() != 11) {
            return false;
        }
        for (char c : pesel_) {
            if (! std::isdigit(c))
                return false;
        }
        int checksum = 0;
        int mults[] = {9, 7, 3, 1, 9, 7, 3, 1, 9, 7};
        for (int i = 0; i < 10; ++ i) {
            checksum += mults[i] * (pesel_[i] - '0');
        }
        checksum %= 10;
        if (checksum != (pesel_[10] - '0'))
            return false;

        return true;
    }
};
