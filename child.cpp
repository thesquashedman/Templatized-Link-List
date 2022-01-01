#include "child.h"

Child::Child()
{
    first_name_ = "a";
    last_name_ = "b";
    age_ = 0;
}

Child::Child(string first_name, string last_name, int age)
{
    first_name_ = first_name;
    last_name_ = last_name;
    age_ = age;
}

void Child::set_child(string first_name, string last_name, int age)
{
    first_name_ = first_name;
    last_name_ = last_name;
    age_ = age;
}

bool Child::operator<(Child other_child)
{
    if (last_name_ < other_child.last_name_)
    {
        return true;
    }
    if (last_name_ == other_child.last_name_)
    {
        if (first_name_ < other_child.first_name_)
        {
            return true;
        }
        if (age_ < other_child.age_)
        {
            return true;
        }
    }
    return false;
}

bool Child::operator>(Child other_child)
{
    if (last_name_ > other_child.last_name_)
    {
        return true;
    }
    if (last_name_ == other_child.last_name_)
    {
        if (first_name_ > other_child.first_name_)
        {
            return true;
        }
        if (age_ > other_child.age_)
        {
            return true;
        }
    }
    return false;
}

bool Child::operator==(Child other_child)
{
    if ((first_name_ == other_child.first_name_) && (last_name_ == other_child.last_name_) && (age_ = other_child.age_))
    {
        return true;
    }
    return false;
}

bool Child::operator!=(Child other_child)
{
    if (!(*this == other_child))
    {
        return true;
    }
    return false;
}

bool Child::operator<=(Child other_child)
{
    if (*this == other_child || *this < other_child)
    {
        return true;
    }
    return false;
}

bool Child::operator>=(Child other_child)
{
    if (*this == other_child || *this > other_child)
    {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& stream, Child& child)
{
    stream << child.first_name_ << child.last_name_ << child.age_;
    return stream;
}

istream& operator>>(istream& stream, Child& child)
{
    string first_name = "a";
    string last_name = "b";
    int age = 1;
    stream >> first_name >> last_name >> age;
    child.set_child(first_name, last_name, age);
    cout << child << endl;
    return stream;
}
