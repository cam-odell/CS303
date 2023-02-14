#include "assignment1header.h"

// boolean function that requests user file name, opens the file, and generates an array in the program from file data
bool generate_array(int arr[], int *length)
{
    string user_file;
    //user input file
    cout << "Please enter file name (if in same directory) or file path with file name to generate array from file data: ";
    cin >> user_file;
    ifstream filepath(user_file);
    // if file doesn't open properly, return message to user
    if(!filepath.is_open())
    {
        cout<<"Designated file failed to open";
        return false;
    }

    *length = 0;
    // generate array from file
    while(filepath >> arr[*length])
    {
        *length = *length + 1;
    }

    filepath.close();

    return true;
}


int find_element(int arr[], int length, int key)
{
    int i;

    for(i = length - 1; i >= 0 ; i--)
        if(arr[i] == key)
            return i;

    return i;
}

int modify_index(int arr[], int index)
{
    cout<<"Enter new desired value: ";
    int key;
    try {
        cin>>key;
        if(std::cin.fail())
            throw 1;
    }
    catch (int err) {
        cout << "Invalid index value, must be an integer value";
        abort();
    }
    arr[index] = key;

    return key;
}

void append_element(int arr[], int *length)
{
    int element;
    cout<<endl<<"Enter new element: ";
    try {
        cin>>element;
        if(std::cin.fail())
            throw 1;
    }
    catch (int err) {
        cout << "Invalid value for element, must be an integer";
        abort();
    }

    arr[*length] = element;

    *length = *length + 1;

    cout<<"Element appended to array";
}

void remove_index(int arr[], int *length)
{
    int index;
    cout<<endl<<"Enter index to be removed: ";
    try {
        cin>>index;
        if(std::cin.fail())
            throw 1;
    }
    catch (int err) {
        cout << "Invalid index value, must be an integer value";
        abort();
    }

    for(int i = index; i < *length - 1; i++)
    arr[i] = arr[i+1];

    *length = *length - 1;

}

void print_array(int arr[], int length)
{
    cout<<endl<<"The elements are: ";

    for(int i=0; i<length; i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main()
{
int arr[50], length, index, key;

    if(!generate_array(arr, &length))
    return 0;

    print_array(arr, length);

    // request user input for element to be searched
    cout<<"Enter the element to be searched: ";
    cin>>key;

    index = find_element(arr, length, key);

    if(index == -1)
    cout<<"Element not found";

    else

    cout<<key<<" is present at index "<<index;

    //request user input for index to be modified
    cout<<endl<<endl<<"Enter the index to be modified: ";
    cin>>index;
    //call modify_index function and print updated array
    int oldindex = arr[index];
    key = modify_index(arr, index);
    cout<<"Former value was " << oldindex <<endl;
    cout<<"Value modified to "<<key;

    cout<<endl<<"Updated Array";
    print_array(arr, length);

    //call append_element function and print updated array
    append_element(arr, &length);

    cout<<endl<<"Updated Array";
    print_array(arr, length);

    //call remove_index function and print updated array
    remove_index(arr, &length);

    cout<<endl<<"Updated Array";
    print_array(arr, length);

return 0;
}
