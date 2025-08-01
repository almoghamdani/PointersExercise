#include "PointerArithmeticTasks.h"
#include "StudentCode.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

// Helper functions for Task 15
int multiplyBy2(int x) { return x * 2; }
int add10(int x) { return x + 10; }
int subtract5(int x) { return x - 5; }

// Task 1: Pointer arithmetic with void pointers and casts
std::string PointerArithmeticTask1::getDescription() const
{
    return "Implement advanceVoidPointer() to advance a void pointer by bytes using casts";
}

void PointerArithmeticTask1::execute()
{
    displayTaskInfo();

    int numbers[] = {10, 20, 30, 40, 50};
    void* ptr = numbers;
    int bytes = 8; // Advance by 8 bytes (2 ints)

    std::cout << "Original void pointer points to: " << *(static_cast<int*>(ptr)) << std::endl;
    std::cout << "Advancing by " << bytes << " bytes..." << std::endl;

    // Test student implementation
    void* result = advanceVoidPointer(ptr, bytes);

    if (result != nullptr)
    {
        std::cout << "After advancing, pointer points to: " << *(static_cast<int*>(result)) << std::endl;
        bool passed = verifyResult(result == static_cast<char*>(ptr) + bytes, "Pointer correctly advanced by bytes");
        passed &= verifyResult(*(static_cast<int*>(result)) == 30, "Pointer points to correct value (30)");

        if (passed)
        {
            // Green color for success
            std::cout << "\033[32m[SUCCESS]\033[0m Task 1 completed successfully!" << std::endl;
        }
        else
        {
            // Red color for failure
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 2: Pointer arithmetic with different integer types
std::string PointerArithmeticTask2::getDescription() const
{
    return "Implement castAndAdvance() to cast char* to int* and advance by offset";
}

void PointerArithmeticTask2::execute()
{
    displayTaskInfo();

    char buffer[20];
    int* intPtr = reinterpret_cast<int*>(buffer);
    intPtr[0] = 100;
    intPtr[1] = 200;
    intPtr[2] = 300;

    char* charPtr = buffer;
    int offset = 2;

    std::cout << "Original char pointer points to buffer" << std::endl;
    std::cout << "Offset: " << offset << " ints" << std::endl;

    // Test student implementation
    int* result = castAndAdvance(charPtr, offset);

    if (result != nullptr)
    {
        std::cout << "After casting and advancing, pointer points to: " << *result << std::endl;
        bool passed = verifyResult(result == intPtr + offset, "Pointer correctly cast and advanced");
        passed &= verifyResult(*result == 300, "Pointer points to correct value (300)");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 2 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 3: Pointer arithmetic with character arrays
std::string PointerArithmeticTask3::getDescription() const
{
    return "Implement advanceCharArrayPointer() to advance a character array pointer by offset";
}

void PointerArithmeticTask3::execute()
{
    displayTaskInfo();

    char charArray[] = "Hello World!";
    char* charPtr = charArray;
    int offset = 6;

    std::cout << "Original character array: \"" << charArray << "\"" << std::endl;
    std::cout << "Original pointer points to: '" << *charPtr << "'" << std::endl;
    std::cout << "Offset: " << offset << " characters" << std::endl;

    // Test student implementation
    char* result = advanceCharArrayPointer(charPtr, offset);

    if (result != nullptr)
    {
        std::cout << "After advancing, pointer points to: '" << *result << "'" << std::endl;
        std::cout << "String from new position: \"" << result << "\"" << std::endl;
        bool passed = verifyResult(result == charPtr + offset, "Character pointer correctly advanced");
        passed &= verifyResult(*result == 'W', "Pointer points to correct character ('W')");
        passed &= verifyResult(strcmp(result, "World!") == 0, "String from new position is correct");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 3 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 4: Complex pointer arithmetic with multiple casts
std::string PointerArithmeticTask4::getDescription() const
{
    return "Implement complexPointerArithmetic() with multiple pointer type casts";
}

void PointerArithmeticTask4::execute()
{
    displayTaskInfo();

    char buffer[32];
    double* doublePtr = reinterpret_cast<double*>(buffer);
    doublePtr[0] = 1.1;
    doublePtr[1] = 2.2;
    doublePtr[2] = 3.3;

    int* intPtr = reinterpret_cast<int*>(buffer);
    long offset = 1;

    std::cout << "Original int pointer points to buffer" << std::endl;
    std::cout << "Offset: " << offset << " doubles" << std::endl;

    // Test student implementation
    double* result = complexPointerArithmetic(intPtr, offset);

    if (result != nullptr)
    {
        std::cout << "After complex arithmetic, pointer points to: " << *result << std::endl;
        bool passed = verifyResult(result == doublePtr + offset, "Pointer correctly advanced with complex arithmetic");
        passed &= verifyResult(*result == 2.2, "Pointer points to correct value (2.2)");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 4 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 5: Pointer arithmetic with struct pointers
std::string PointerArithmeticTask5::getDescription() const
{
    return "Implement advanceStructPointer() to advance a struct pointer by elements";
}

void PointerArithmeticTask5::execute()
{
    displayTaskInfo();

    Point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    Point* ptr = points;
    int elements = 2;

    std::cout << "Original struct pointer points to: (" << ptr->x << ", " << ptr->y << ")" << std::endl;
    std::cout << "Advancing by " << elements << " elements..." << std::endl;

    // Test student implementation
    Point* result = advanceStructPointer(ptr, elements);

    if (result != nullptr)
    {
        std::cout << "After advancing, pointer points to: (" << result->x << ", " << result->y << ")" << std::endl;
        bool passed = verifyResult(result == ptr + elements, "Struct pointer correctly advanced");
        passed &= verifyResult(result->x == 5 && result->y == 6, "Pointer points to correct struct (5, 6)");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 5 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 6: Pointer arithmetic with const pointers
std::string PointerArithmeticTask6::getDescription() const
{
    return "Implement advanceConstPointer() to advance a const pointer by offset";
}

void PointerArithmeticTask6::execute()
{
    displayTaskInfo();

    const int numbers[] = {10, 20, 30, 40, 50};
    const int* ptr = numbers;
    int offset = 3;

    std::cout << "Original const pointer points to: " << *ptr << std::endl;
    std::cout << "Offset: " << offset << std::endl;

    // Test student implementation
    const int* result = advanceConstPointer(ptr, offset);

    if (result != nullptr)
    {
        std::cout << "After advancing, const pointer points to: " << *result << std::endl;
        bool passed = verifyResult(result == ptr + offset, "Const pointer correctly advanced");
        passed &= verifyResult(*result == 40, "Pointer points to correct value (40)");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 6 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 7: Pointer arithmetic with volatile pointers
std::string PointerArithmeticTask7::getDescription() const
{
    return "Implement advanceVolatilePointer() to advance a volatile pointer by bytes";
}

void PointerArithmeticTask7::execute()
{
    displayTaskInfo();

    volatile char buffer[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    volatile char* ptr = buffer;
    int bytes = 3;

    std::cout << "Original volatile pointer points to: '" << *ptr << "'" << std::endl;
    std::cout << "Advancing by " << bytes << " bytes..." << std::endl;

    // Test student implementation
    volatile char* result = advanceVolatilePointer(ptr, bytes);

    if (result != nullptr)
    {
        std::cout << "After advancing, volatile pointer points to: '" << *result << "'" << std::endl;
        bool passed = verifyResult(result == ptr + bytes, "Volatile pointer correctly advanced");
        passed &= verifyResult(*result == 'D', "Pointer points to correct value ('D')");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 7 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 8: Pointer arithmetic with array of pointers
std::string PointerArithmeticTask8::getDescription() const
{
    return "Implement advancePointerArray() to advance in an array of pointers";
}

void PointerArithmeticTask8::execute()
{
    displayTaskInfo();

    int a = 10, b = 20, c = 30, d = 40;
    int* ptrArray[] = {&a, &b, &c, &d};
    int** ptr = ptrArray;
    int index = 2;

    std::cout << "Original pointer array points to: " << **ptr << std::endl;
    std::cout << "Index: " << index << std::endl;

    // Test student implementation
    int** result = advancePointerArray(ptr, index);

    if (result != nullptr)
    {
        std::cout << "After advancing, pointer array points to: " << **result << std::endl;
        bool passed = verifyResult(result == ptr + index, "Pointer array correctly advanced");
        passed &= verifyResult(**result == 30, "Pointer points to correct value (30)");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 8 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 9: Basic pointer-to-pointer assignment
std::string PointerArithmeticTask9::getDescription() const
{
    return "Implement assignValueThroughPointer() to assign a value through a pointer-to-pointer";
}

void PointerArithmeticTask9::execute()
{
    displayTaskInfo();

    int value = 42;
    int* ptr = &value;
    int** ptrToPtr = &ptr;
    int newValue = 100;

    std::cout << "Original value: " << **ptrToPtr << std::endl;
    std::cout << "New value to assign: " << newValue << std::endl;

    // Test student implementation
    assignValueThroughPointer(ptrToPtr, newValue);

    std::cout << "After assignment: " << **ptrToPtr << std::endl;
    bool passed = verifyResult(**ptrToPtr == newValue, "Value correctly assigned through pointer-to-pointer");
    passed &= verifyResult(*ptr == newValue, "Value correctly stored in the pointed variable");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 9 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 10: Allocate memory through pointer-to-pointer
std::string PointerArithmeticTask10::getDescription() const
{
    return "Implement allocateMemory() to allocate memory and assign it through pointer-to-pointer";
}

void PointerArithmeticTask10::execute()
{
    displayTaskInfo();

    int* ptr = nullptr;
    int** ptrToPtr = &ptr;
    int size = 5;

    std::cout << "Original pointer: " << (ptr == nullptr ? "nullptr" : "not nullptr") << std::endl;
    std::cout << "Allocating " << size << " integers..." << std::endl;

    // Test student implementation
    allocateMemory(ptrToPtr, size);

    if (*ptrToPtr != nullptr)
    {
        std::cout << "After allocation: " << (*ptrToPtr == nullptr ? "nullptr" : "not nullptr") << std::endl;

        // Test that we can write to the allocated memory
        for (int i = 0; i < size; ++i)
        {
            (*ptrToPtr)[i] = i * 10;
        }

        bool passed = verifyResult(*ptrToPtr != nullptr, "Memory successfully allocated");
        passed &= verifyResult((*ptrToPtr)[0] == 0, "Can write to allocated memory");
        passed &= verifyResult((*ptrToPtr)[size - 1] == (size - 1) * 10, "Can write to end of allocated memory");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 10 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }

        // Clean up
        delete[] *ptrToPtr;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Memory allocation failed - implementation incomplete" << std::endl;
    }
}

// Task 11: Swap pointers using pointer-to-pointer
std::string PointerArithmeticTask11::getDescription() const
{
    return "Implement swapPointers() to swap the pointers that ptr1 and ptr2 point to";
}

void PointerArithmeticTask11::execute()
{
    displayTaskInfo();

    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;
    int** ptrToPtr1 = &ptr1;
    int** ptrToPtr2 = &ptr2;

    std::cout << "Before swap: ptr1 points to " << **ptrToPtr1 << ", ptr2 points to " << **ptrToPtr2 << std::endl;

    // Test student implementation
    swapPointers(ptrToPtr1, ptrToPtr2);

    std::cout << "After swap: ptr1 points to " << **ptrToPtr1 << ", ptr2 points to " << **ptrToPtr2 << std::endl;
    bool passed = verifyResult(**ptrToPtr1 == 20, "ptr1 now points to the value that ptr2 originally pointed to");
    passed &= verifyResult(**ptrToPtr2 == 10, "ptr2 now points to the value that ptr1 originally pointed to");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 11 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 12: Return multiple values through pointer-to-pointer
std::string PointerArithmeticTask12::getDescription() const
{
    return "Implement getMinMax() to find min and max values and assign them through pointers";
}

void PointerArithmeticTask12::execute()
{
    displayTaskInfo();

    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = 6;
    int* minPtr = nullptr;
    int* maxPtr = nullptr;
    int** ptrToMinPtr = &minPtr;
    int** ptrToMaxPtr = &maxPtr;

    std::cout << "Array: [5, 2, 8, 1, 9, 3]" << std::endl;
    std::cout << "Expected min: 1, Expected max: 9" << std::endl;

    // Test student implementation
    getMinMax(arr, size, ptrToMinPtr, ptrToMaxPtr);

    if (minPtr != nullptr && maxPtr != nullptr)
    {
        std::cout << "Found min: " << *minPtr << " at index " << (minPtr - arr) << std::endl;
        std::cout << "Found max: " << *maxPtr << " at index " << (maxPtr - arr) << std::endl;

        bool passed = verifyResult(*minPtr == 1, "Minimum value correctly found");
        passed &= verifyResult(*maxPtr == 9, "Maximum value correctly found");
        passed &= verifyResult(minPtr >= arr && minPtr < arr + size, "Min pointer points to valid array element");
        passed &= verifyResult(maxPtr >= arr && maxPtr < arr + size, "Max pointer points to valid array element");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 12 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function failed to assign pointers - implementation incomplete" <<
                std::endl;
    }
}

// Task 13: Pointer-to-pointer with struct
std::string PointerArithmeticTask13::getDescription() const
{
    return "Implement insertNodeAtBeginning() to insert a new node at the beginning of a linked list";
}

void PointerArithmeticTask13::execute()
{
    displayTaskInfo();

    Node* head = nullptr;
    Node** headPtr = &head;
    int value = 42;

    std::cout << "Original head: " << (head == nullptr ? "nullptr" : "not nullptr") << std::endl;
    std::cout << "Inserting value: " << value << std::endl;

    // Test student implementation
    insertNodeAtBeginning(headPtr, value);

    if (head != nullptr)
    {
        std::cout << "After insertion: head points to node with value " << head->data << std::endl;
        bool passed = verifyResult(head->data == value, "New node has correct value");
        passed &= verifyResult(head->next == nullptr, "New node's next pointer is nullptr");

        // Insert another node
        insertNodeAtBeginning(headPtr, 100);
        passed &= verifyResult(head->data == 100, "Second insertion works correctly");
        passed &= verifyResult(head->next->data == value, "Second node points to first node");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 13 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }

        // Clean up
        delete head->next;
        delete head;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Node insertion failed - implementation incomplete" << std::endl;
    }
}

// Task 14: Pointer-to-pointer array allocation
std::string PointerArithmeticTask14::getDescription() const
{
    return "Implement allocate2DArray() to allocate a 2D array through pointer-to-pointer";
}

void PointerArithmeticTask14::execute()
{
    displayTaskInfo();

    int** array2D = nullptr;
    int*** ptrToArray2D = &array2D;
    int rows = 3, cols = 4;

    std::cout << "Original array2D: " << (array2D == nullptr ? "nullptr" : "not nullptr") << std::endl;
    std::cout << "Allocating " << rows << "x" << cols << " array..." << std::endl;

    // Test student implementation
    allocate2DArray(ptrToArray2D, rows, cols);

    if (array2D != nullptr)
    {
        std::cout << "After allocation: " << (array2D == nullptr ? "nullptr" : "not nullptr") << std::endl;

        // Test that we can write to the allocated memory
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                array2D[i][j] = i * 10 + j;
            }
        }

        bool passed = verifyResult(array2D != nullptr, "2D array successfully allocated");
        passed &= verifyResult(array2D[0] != nullptr, "First row successfully allocated");
        passed &= verifyResult(array2D[rows - 1] != nullptr, "Last row successfully allocated");
        passed &= verifyResult(array2D[0][0] == 0, "Can write to first element");
        passed &= verifyResult(array2D[rows - 1][cols - 1] == (rows - 1) * 10 + (cols - 1),
                               "Can write to last element");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 14 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }

        // Clean up
        for (int i = 0; i < rows; ++i)
        {
            delete[] array2D[i];
        }
        delete[] array2D;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m 2D array allocation failed - implementation incomplete" << std::endl;
    }
}

// Task 15: Pointer-to-pointer function pointer
std::string PointerArithmeticTask15::getDescription() const
{
    return "Implement assignFunctionPointer() to assign a function pointer based on choice";
}

void PointerArithmeticTask15::execute()
{
    displayTaskInfo();

    int (*funcPtr)(int) = nullptr;
    int (**ptrToFuncPtr)(int) = &funcPtr;
    int choice = 1;
    int testValue = 5;

    std::cout << "Original function pointer: " << (funcPtr == nullptr ? "nullptr" : "not nullptr") << std::endl;
    std::cout << "Choice: " << choice << " (should assign multiplyBy2)" << std::endl;

    // Test student implementation
    assignFunctionPointer(ptrToFuncPtr, choice);

    if (funcPtr != nullptr)
    {
        int result = funcPtr(testValue);
        std::cout << "After assignment: function(5) = " << result << std::endl;
        bool passed = verifyResult(funcPtr == multiplyBy2, "Correct function pointer assigned");
        passed &= verifyResult(result == 10, "Function works correctly (5 * 2 = 10)");

        // Test another choice
        assignFunctionPointer(ptrToFuncPtr, 2);
        result = funcPtr(testValue);
        passed &= verifyResult(funcPtr == add10, "Second function pointer assigned correctly");
        passed &= verifyResult(result == 15, "Second function works correctly (5 + 10 = 15)");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 15 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function pointer assignment failed - implementation incomplete" <<
                std::endl;
    }
}

// Task 16: Complex pointer-to-pointer arithmetic
std::string PointerArithmeticTask16::getDescription() const
{
    return "Implement advancePointerToPointer() to advance a pointer-to-pointer-to-pointer by offset";
}

void PointerArithmeticTask16::execute()
{
    displayTaskInfo();

    int a = 10, b = 20, c = 30;
    int* ptr1 = &a;
    int* ptr2 = &b;
    int* ptr3 = &c;
    int** ptrToPtr1 = &ptr1;
    int** ptrToPtr2 = &ptr2;
    int** ptrToPtr3 = &ptr3;
    int*** ptrToPtrToPtr = &ptrToPtr1;
    int offset = 1;

    std::cout << "Original pointer-to-pointer-to-pointer points to: " << ***ptrToPtrToPtr << std::endl;
    std::cout << "Offset: " << offset << std::endl;

    // Test student implementation
    advancePointerToPointer(ptrToPtrToPtr, offset);

    std::cout << "After advancing, points to: " << ***ptrToPtrToPtr << std::endl;
    bool passed = verifyResult(ptrToPtrToPtr == &ptrToPtr2, "Pointer-to-pointer-to-pointer correctly advanced");
    passed &= verifyResult(***ptrToPtrToPtr == 20, "Points to correct value (20)");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 16 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 17: Extract wstring from vector<uint8_t>
std::string PointerArithmeticTask17::getDescription() const
{
    return "Implement extractWStringFromVector() to extract a wstring from a vector at the given offset";
}

void PointerArithmeticTask17::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data(50, 0);
    std::wstring testString = L"Hello World";
    size_t offset = 10;

    // Copy wstring data to vector at offset
    std::memcpy(&data[offset], testString.data(), testString.size() * sizeof(wchar_t));

    std::cout << "Vector size: " << data.size() << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected string: " << testString.c_str() << std::endl;

    // Test student implementation
    std::wstring result = extractWStringFromVector(data, offset);

    std::cout << "Extracted string: " << result.c_str() << std::endl;
    bool passed = verifyResult(result == testString, "Correctly extracted wstring from vector");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 17 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 18: Create vector<uint8_t> from uint32_t
std::string PointerArithmeticTask18::getDescription() const
{
    return "Implement createVectorFromUint32() to create a vector from a uint32_t value";
}

void PointerArithmeticTask18::execute()
{
    displayTaskInfo();

    uint32_t testValue = 0x12345678;

    std::cout << "Input uint32_t: 0x" << std::hex << testValue << std::dec << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = createVectorFromUint32(testValue);

    std::cout << "Result vector size: " << result.size() << std::endl;
    std::cout << "Expected size: " << sizeof(uint32_t) << std::endl;

    bool passed = verifyResult(result.size() == sizeof(uint32_t), "Vector has correct size");

    if (passed)
    {
        uint32_t extractedValue;
        std::memcpy(&extractedValue, result.data(), sizeof(uint32_t));
        passed &= verifyResult(extractedValue == testValue, "Vector contains correct uint32_t value");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 18 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 19: Extract uint32_t from vector<uint8_t>
std::string PointerArithmeticTask19::getDescription() const
{
    return "Implement extractUint32FromVector() to extract a uint32_t from a vector at the given offset";
}

void PointerArithmeticTask19::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data(20, 0);
    uint32_t testValue = 0xABCD1234;
    size_t offset = 5;

    // Copy uint32_t to vector at offset
    std::memcpy(&data[offset], &testValue, sizeof(uint32_t));

    std::cout << "Vector size: " << data.size() << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected value: 0x" << std::hex << testValue << std::dec << std::endl;

    // Test student implementation
    uint32_t result = extractUint32FromVector(data, offset);

    std::cout << "Extracted value: 0x" << std::hex << result << std::dec << std::endl;
    bool passed = verifyResult(result == testValue, "Correctly extracted uint32_t from vector");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 19 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 20: Create vector<uint8_t> from POD struct
std::string PointerArithmeticTask20::getDescription() const
{
    return "Implement createVectorFromPOD() to create a vector from a POD struct";
}

void PointerArithmeticTask20::execute()
{
    displayTaskInfo();

    PODStruct testPod = {0x1234, 0x567890AB, 0xCD};

    std::cout << "Input POD - ID: 0x" << std::hex << testPod.id
            << ", Value: 0x" << testPod.value
            << ", Flags: 0x" << (int)testPod.flags << std::dec << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = createVectorFromPOD(testPod);

    std::cout << "Result vector size: " << result.size() << std::endl;
    std::cout << "Expected size: " << sizeof(PODStruct) << std::endl;

    bool passed = verifyResult(result.size() == sizeof(PODStruct), "Vector has correct size");

    if (passed)
    {
        PODStruct extractedPod;
        std::memcpy(&extractedPod, result.data(), sizeof(PODStruct));
        passed &= verifyResult(extractedPod.id == testPod.id, "POD ID correctly stored");
        passed &= verifyResult(extractedPod.value == testPod.value, "POD value correctly stored");
        passed &= verifyResult(extractedPod.flags == testPod.flags, "POD flags correctly stored");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 20 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 21: Extract POD struct from vector<uint8_t>
std::string PointerArithmeticTask21::getDescription() const
{
    return "Implement extractPODFromVector() to extract a POD struct from a vector at the given offset";
}

void PointerArithmeticTask21::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data(30, 0);
    PODStruct testPod = {0xABCD, 0x12345678, 0xEF};
    size_t offset = 8;

    // Copy POD to vector at offset
    std::memcpy(&data[offset], &testPod, sizeof(PODStruct));

    std::cout << "Vector size: " << data.size() << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected POD - ID: 0x" << std::hex << testPod.id
            << ", Value: 0x" << testPod.value
            << ", Flags: 0x" << (int)testPod.flags << std::dec << std::endl;

    // Test student implementation
    PODStruct result = extractPODFromVector(data, offset);

    std::cout << "Extracted POD - ID: 0x" << std::hex << result.id
            << ", Value: 0x" << result.value
            << ", Flags: 0x" << (int)result.flags << std::dec << std::endl;

    bool passed = verifyResult(result.id == testPod.id, "POD ID correctly extracted");
    passed &= verifyResult(result.value == testPod.value, "POD value correctly extracted");
    passed &= verifyResult(result.flags == testPod.flags, "POD flags correctly extracted");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 21 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 22: Convert vector<uint8_t> to vector<uint32_t>
std::string PointerArithmeticTask22::getDescription() const
{
    return "Implement convertToUint32Vector() to convert a vector of uint8_t to uint32_t";
}

void PointerArithmeticTask22::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};
    std::vector<uint32_t> expected = {0x78563412, 0xF0DEBC9A}; // Little-endian

    std::cout << "Input vector size: " << data.size() << std::endl;
    std::cout << "Expected uint32_t count: " << expected.size() << std::endl;

    // Test student implementation
    std::vector<uint32_t> result = convertToUint32Vector(data);

    std::cout << "Result vector size: " << result.size() << std::endl;

    bool passed = verifyResult(result.size() == expected.size(), "Vector has correct size");

    if (passed)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            std::cout << "Result[" << i << "]: 0x" << std::hex << result[i]
                    << ", Expected: 0x" << expected[i] << std::dec << std::endl;
            passed &= verifyResult(result[i] == expected[i], "Value correctly converted");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 22 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 23: Convert vector<uint32_t> to vector<uint8_t>
std::string PointerArithmeticTask23::getDescription() const
{
    return "Implement convertToUint8Vector() to convert a vector of uint32_t to uint8_t";
}

void PointerArithmeticTask23::execute()
{
    displayTaskInfo();

    std::vector<uint32_t> data = {0x12345678, 0x9ABCDEF0};
    std::vector<uint8_t> expected = {0x78, 0x56, 0x34, 0x12, 0xF0, 0xDE, 0xBC, 0x9A}; // Little-endian

    std::cout << "Input vector size: " << data.size() << std::endl;
    std::cout << "Expected uint8_t count: " << expected.size() << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = convertToUint8Vector(data);

    std::cout << "Result vector size: " << result.size() << std::endl;

    bool passed = verifyResult(result.size() == expected.size(), "Vector has correct size");

    if (passed)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            std::cout << "Result[" << i << "]: 0x" << std::hex << (int)result[i]
                    << ", Expected: 0x" << (int)expected[i] << std::dec << std::endl;
            passed &= verifyResult(result[i] == expected[i], "Value correctly converted");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 23 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 24: Insert wstring into vector<uint8_t> at offset
std::string PointerArithmeticTask24::getDescription() const
{
    return "Implement insertWStringIntoVector() to insert a wstring into a vector at the given offset";
}

void PointerArithmeticTask24::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data(50, 0);
    std::wstring testString = L"Test String";
    size_t offset = 15;

    std::cout << "Vector size: " << data.size() << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "String to insert: " << testString.c_str() << std::endl;

    // Test student implementation
    insertWStringIntoVector(data, testString, offset);

    // Verify the insertion
    std::wstring extracted = std::wstring(reinterpret_cast<const wchar_t*>(&data[offset]));

    std::cout << "Extracted string: " << extracted.c_str() << std::endl;
    bool passed = verifyResult(extracted == testString, "String correctly inserted into vector");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 24 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 25: Extract wstring from complex struct at data offset
std::string PointerArithmeticTask25::getDescription() const
{
    return "Implement extractWStringFromComplexStruct() to extract a wstring from a complex struct";
}

void PointerArithmeticTask25::execute()
{
    displayTaskInfo();

    std::wstring testString = L"Hello World!";
    size_t dataSize = testString.size() * sizeof(wchar_t);

    // Allocate memory for struct + data
    uint8_t* buffer = new uint8_t[sizeof(ComplexStruct) + dataSize];
    ComplexStruct* complexStruct = reinterpret_cast<ComplexStruct*>(buffer);

    complexStruct->header = 0x12345678;
    complexStruct->flags = 0xABCD;
    complexStruct->dataType = 1; // 1 = wstring
    complexStruct->dataOffset = 0; // Start at beginning of data after struct
    complexStruct->dataLength = dataSize; // Size in bytes

    // Copy data after the struct
    uint8_t* dataPtr = buffer + sizeof(ComplexStruct);
    std::memcpy(dataPtr, testString.data(), dataSize);

    std::cout << "Complex struct header: 0x" << std::hex << complexStruct->header << std::dec << std::endl;
    std::cout << "Data type: " << (int)complexStruct->dataType << " (wstring)" << std::endl;
    std::cout << "Data offset: " << complexStruct->dataOffset << std::endl;
    std::cout << "Data length: " << complexStruct->dataLength << std::endl;
    std::cout << "Expected string: " << testString.c_str() << std::endl;

    // Test student implementation
    std::wstring result = extractWStringFromComplexStruct(complexStruct);

    std::cout << "Extracted string: " << result.c_str() << std::endl;
    bool passed = verifyResult(result == testString, "Correctly extracted wstring from complex struct");

    delete[] buffer;

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 25 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 26: Extract raw data from complex struct with length validation
std::string PointerArithmeticTask26::getDescription() const
{
    return "Implement extractRawDataFromComplexStruct() to extract raw data with length validation";
}

void PointerArithmeticTask26::execute()
{
    displayTaskInfo();

    uint8_t testData[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};
    size_t dataSize = sizeof(testData);

    // Allocate memory for struct + data
    uint8_t* buffer = new uint8_t[sizeof(ComplexStruct) + dataSize];
    ComplexStruct* complexStruct = reinterpret_cast<ComplexStruct*>(buffer);

    complexStruct->header = 0x87654321;
    complexStruct->flags = 0xDCBA;
    complexStruct->dataType = 2; // 2 = raw data
    complexStruct->dataOffset = 0;
    complexStruct->dataLength = dataSize;

    // Copy data after the struct
    uint8_t* dataPtr = buffer + sizeof(ComplexStruct);
    std::memcpy(dataPtr, testData, dataSize);

    std::cout << "Complex struct header: 0x" << std::hex << complexStruct->header << std::dec << std::endl;
    std::cout << "Data type: " << (int)complexStruct->dataType << " (raw data)" << std::endl;
    std::cout << "Data length: " << complexStruct->dataLength << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = extractRawDataFromComplexStruct(complexStruct);

    std::cout << "Extracted data size: " << result.size() << std::endl;
    bool passed = verifyResult(result.size() == complexStruct->dataLength, "Correct data length extracted");

    if (passed)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            std::cout << "Result[" << i << "]: 0x" << std::hex << (int)result[i]
                    << ", Expected: 0x" << (int)testData[i] << std::dec << std::endl;
            passed &= verifyResult(result[i] == testData[i], "Data correctly extracted");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 26 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    delete[] buffer;
}

// Task 27: Extract wstring from nested struct traversal
std::string PointerArithmeticTask27::getDescription() const
{
    return "Implement extractWStringFromNestedStruct() to extract wstring by traversing struct offsets";
}

void PointerArithmeticTask27::execute()
{
    displayTaskInfo();

    std::wstring testString1 = L"First";
    std::wstring testString2 = L"Second String";
    size_t dataSize1 = testString1.size() * sizeof(wchar_t);
    size_t dataSize2 = testString2.size() * sizeof(wchar_t);

    // Create a buffer with multiple structs + data
    size_t totalSize = 128 + sizeof(ComplexStruct) + dataSize2;
    uint8_t* buffer = new uint8_t[totalSize];
    std::memset(buffer, 0, totalSize);

    // First struct at offset 0
    ComplexStruct* struct1 = reinterpret_cast<ComplexStruct*>(buffer);
    struct1->header = 0x11111111;
    struct1->dataType = 1;
    struct1->dataOffset = 0;
    struct1->dataLength = dataSize1;

    // Copy data after first struct
    uint8_t* dataPtr1 = buffer + sizeof(ComplexStruct);
    std::memcpy(dataPtr1, testString1.data(), dataSize1);

    // Second struct at offset 128
    ComplexStruct* struct2 = reinterpret_cast<ComplexStruct*>(buffer + 128);
    struct2->header = 0x22222222;
    struct2->dataType = 1;
    struct2->dataOffset = 0;
    struct2->dataLength = dataSize2;

    // Copy data after second struct
    uint8_t* dataPtr2 = buffer + 128 + sizeof(ComplexStruct);
    std::memcpy(dataPtr2, testString2.data(), dataSize2);

    std::cout << "Buffer size: " << totalSize << std::endl;
    std::cout << "Struct offset: 128" << std::endl;
    std::cout << "Expected string: " << testString2.c_str() << std::endl;

    // Test student implementation
    std::wstring result = extractWStringFromNestedStruct(buffer, 128);

    std::cout << "Extracted string: " << result.c_str() << std::endl;
    bool passed = verifyResult(result == testString2, "Correctly extracted wstring from nested struct");

    delete[] buffer;

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 27 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 28: Extract variable length data with offset calculation
std::string PointerArithmeticTask28::getDescription() const
{
    return "Implement extractVariableLengthData() to extract data using offset and length";
}

void PointerArithmeticTask28::execute()
{
    displayTaskInfo();

    // Create a buffer with mixed data
    std::vector<uint8_t> buffer = {
        0xAA,
        0xBB,
        0xCC,
        0xDD,
        // Header
        0x11,
        0x22,
        0x33,
        0x44,
        // Some data
        0x55,
        0x66,
        0x77,
        0x88,
        // More data
        0x99,
        0xAA,
        0xBB,
        0xCC // Target data
    };

    uint32_t dataOffset = 8; // Start at byte 8
    uint32_t dataLength = 4; // Extract 4 bytes

    std::vector<uint8_t> expectedData = {0x55, 0x66, 0x77, 0x88};

    std::cout << "Buffer size: " << buffer.size() << std::endl;
    std::cout << "Data offset: " << dataOffset << std::endl;
    std::cout << "Data length: " << dataLength << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = extractVariableLengthData(buffer.data(), dataOffset, dataLength);

    std::cout << "Extracted data size: " << result.size() << std::endl;
    bool passed = verifyResult(result.size() == dataLength, "Correct data length extracted");

    if (passed)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            std::cout << "Result[" << i << "]: 0x" << std::hex << (int)result[i]
                    << ", Expected: 0x" << (int)expectedData[i] << std::dec << std::endl;
            passed &= verifyResult(result[i] == expectedData[i], "Data correctly extracted");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 28 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 29: Fix incorrect pointer type causing wrong data copy
std::string PointerArithmeticTask29::getDescription() const
{
    return "Debug and fix copyDataFromBuffer() - wide character data is not being copied correctly from the source buffer";
}

void PointerArithmeticTask29::execute()
{
    displayTaskInfo();

    // Create test data with wide character content containing uppercase letters
    std::wstring testString = L"HELLO WORLD!";
    size_t wideCharSize = testString.size() * sizeof(wchar_t);
    
    // Create source buffer with wide character data
    uint8_t sourceBuffer[50] = {0};
    std::memcpy(sourceBuffer, testString.data(), wideCharSize);
    
    // Add some padding bytes after the wide character data
    for (size_t i = wideCharSize; i < 50; ++i) {
        sourceBuffer[i] = static_cast<uint8_t>(i);
    }

    uint8_t destinationBuffer[50] = {0};
    size_t offset = 0;  // Start from beginning of wide character data
    size_t length = wideCharSize;  // Copy the entire wide character string

    std::cout << "Source contains wide character string: " << testString.c_str() << std::endl;
    std::cout << "Wide character size: " << wideCharSize << " bytes" << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Length: " << length << " bytes" << std::endl;
    std::cout << "Expected result (lowercase): hello world!" << std::endl;

    // Test student implementation
    copyDataFromBuffer(destinationBuffer, sourceBuffer, offset, length);

    // Verify the copied data by reconstructing the wide character string
    std::wstring copiedString(reinterpret_cast<const wchar_t*>(destinationBuffer), testString.size());
    
    std::cout << "Copied string: " << copiedString.c_str() << std::endl;

    // Check if the string was converted to lowercase
    std::wstring expectedLowercase = L"hello world!";
    bool passed = verifyResult(copiedString == expectedLowercase, "Wide character data correctly copied and converted to lowercase");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 29 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        std::cout << "Hint: The bug is in how the wide character pointer is being advanced during copying" << std::endl;
    }
}

// Task 30: Fix wrong pointer offset in pointer-to-pointer scenario
std::string PointerArithmeticTask30::getDescription() const
{
    return "Debug and fix readDataWithOffset() - the function is reading from the wrong memory location";
}

void PointerArithmeticTask30::execute()
{
    displayTaskInfo();

    // Create test data
    uint32_t dataArray[10] = {
        0x11111111,
        0x22222222,
        0x33333333,
        0x44444444,
        0x55555555,
        0x66666666,
        0x77777777,
        0x88888888,
        0x99999999,
        0xAAAAAAAA
    };

    uint32_t* dataPtr = dataArray;
    uint32_t** ptrToPtr = &dataPtr;
    size_t offset = 3;

    std::cout << "Data array (first 8 elements): ";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "0x" << std::hex << dataArray[i] << " ";
    }
    std::cout << std::dec << std::endl;

    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected value: 0x" << std::hex << dataArray[offset] << std::dec << std::endl;

    // Test student implementation
    uint32_t result = readDataWithOffset(ptrToPtr, offset);

    std::cout << "Read value: 0x" << std::hex << result << std::dec << std::endl;
    bool passed = verifyResult(result == dataArray[offset], "Correctly read data with offset");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 30 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 31: Fix incorrect dereferencing of uint8_t* to uint32_t
std::string PointerArithmeticTask31::getDescription() const
{
    return "Debug and fix readUint32FromBuffer() - the function is not correctly reading the uint32_t value";
}

void PointerArithmeticTask31::execute()
{
    displayTaskInfo();

    // Create test data
    uint8_t buffer[16] = {
        0x12,
        0x34,
        0x56,
        0x78,
        // First uint32_t: 0x78563412 (little endian)
        0x9A,
        0xBC,
        0xDE,
        0xF0,
        // Second uint32_t: 0xF0DEBC9A
        0x11,
        0x22,
        0x33,
        0x44,
        // Third uint32_t: 0x44332211
        0x55,
        0x66,
        0x77,
        0x88 // Fourth uint32_t: 0x88776655
    };

    size_t offset = 4; // Read second uint32_t
    uint32_t expectedValue = 0xF0DEBC9A; // Little endian

    std::cout << "Buffer (16 bytes): ";
    for (int i = 0; i < 16; ++i)
    {
        std::cout << "0x" << std::hex << (int)buffer[i] << " ";
    }
    std::cout << std::dec << std::endl;

    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected uint32_t: 0x" << std::hex << expectedValue << std::dec << std::endl;

    // Test student implementation
    uint32_t result = readUint32FromBuffer(buffer, offset);

    std::cout << "Read uint32_t: 0x" << std::hex << result << std::dec << std::endl;
    bool passed = verifyResult(result == expectedValue, "Correctly read uint32_t from buffer");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 31 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 32: Fix complex struct traversal and pointer arithmetic bug
std::string PointerArithmeticTask32::getDescription() const
{
    return "Debug and fix the struct traversal logic - data pointers are not being extracted correctly";
}

void PointerArithmeticTask32::execute()
{
    displayTaskInfo();

    // Create a data structure in memory
    size_t structureSize = sizeof(DataHeader) + (3 * sizeof(DataBlock)) + (3 * 64); // 3 blocks with 64 bytes each
    uint8_t* buffer = new uint8_t[structureSize];
    std::memset(buffer, 0, structureSize);

    // Set up header
    DataHeader* header = reinterpret_cast<DataHeader*>(buffer);
    header->magic = 0x12345678;
    header->version = 1;
    header->flags = 0;
    header->dataSize = 3 * 64; // 3 blocks of 64 bytes each
    header->checksum = 0;

    // Set up blocks
    DataBlock* blocks = reinterpret_cast<DataBlock*>(buffer + sizeof(DataHeader));
    uint8_t* dataArea = buffer + sizeof(DataHeader) + (3 * sizeof(DataBlock));

    for (int i = 0; i < 3; ++i)
    {
        blocks[i].blockId = i + 1;
        blocks[i].blockType = 1;
        blocks[i].reserved = 0;
        blocks[i].offset = i * 64;
        blocks[i].length = 64;
        blocks[i].dataPtr = dataArea + (i * 64);

        // Fill data with test values
        for (int j = 0; j < 64; ++j)
        {
            blocks[i].dataPtr[j] = static_cast<uint8_t>(i * 100 + j);
        }
    }

    std::cout << "Created data structure with 3 blocks" << std::endl;
    std::cout << "Block 0 data pointer: 0x" << std::hex << reinterpret_cast<uintptr_t>(blocks[0].dataPtr) << std::dec <<
            std::endl;

    uint32_t resultCount = 0;
    bool success = traverseDataStructure(buffer, structureSize, &resultCount);

    std::cout << "Traversal result: " << (success ? "SUCCESS" : "FAILED") << std::endl;
    std::cout << "Result count: " << resultCount << std::endl;

    bool passed = verifyResult(success && resultCount == 3, "Data structure traversed correctly");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 32 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    delete[] buffer;
}

// Task 33: Fix complex memory management and pointer validation bug
std::string PointerArithmeticTask33::getDescription() const
{
    return "Debug and fix the memory management system - data blocks are not being allocated correctly";
}

void PointerArithmeticTask33::execute()
{
    displayTaskInfo();

    // Create a processing context
    ProcessingContext* context = nullptr;
    bool success = allocateProcessingContext(&context, 800);

    if (!success || !context)
    {
        std::cout << "\033[31m[FAILED]\033[0m Failed to allocate processing context" << std::endl;
        return;
    }

    std::cout << "Allocated processing context with buffer size: " << context->bufferSize << std::endl;
    std::cout << "Expected total data size for 5 blocks of 64 bytes each: " << (5 * 64) << " bytes" << std::endl;

    // Initialize with 5 data blocks
    success = initializeDataBlocks(context, 5);

    std::cout << "Initialization result: " << (success ? "SUCCESS" : "FAILED") << std::endl;
    std::cout << "Block count: " << context->blockCount << std::endl;
    std::cout << "Current offset: " << context->currentOffset << std::endl;

    // Debug: Show memory layout
    std::cout << "Memory layout:" << std::endl;
    for (uint32_t i = 0; i < context->blockCount; ++i)
    {
        DataBlock* block = &context->blocks[i];
        std::cout << "Block " << i << ": offset=" << block->offset
                << ", length=" << block->length
                << ", dataPtr=0x" << std::hex << reinterpret_cast<uintptr_t>(block->dataPtr) << std::dec
                << ", end=0x" << std::hex << reinterpret_cast<uintptr_t>(block->dataPtr + block->length) << std::dec <<
                std::endl;
    }

    // Check if blocks are properly allocated
    bool blocksValid = true;
    for (uint32_t i = 0; i < context->blockCount; ++i)
    {
        DataBlock* block = &context->blocks[i];
        if (block->blockId != i + 1 || block->length != 64)
        {
            blocksValid = false;
            break;
        }

        // Check if data pointer is within buffer bounds
        if (block->dataPtr < context->buffer ||
            block->dataPtr + block->length > context->buffer + context->bufferSize)
        {
            blocksValid = false;
            break;
        }

        // Check for memory overlap with previous blocks
        for (uint32_t j = 0; j < i; ++j)
        {
            DataBlock* prevBlock = &context->blocks[j];
            if (block->dataPtr >= prevBlock->dataPtr &&
                block->dataPtr < prevBlock->dataPtr + prevBlock->length)
            {
                blocksValid = false;
                break;
            }
        }

        if (!blocksValid) break;
    }

    bool passed = verifyResult(success && blocksValid, "Data blocks allocated correctly");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 33 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    cleanupProcessingContext(context);
}
