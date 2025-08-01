#pragma once
#include <vector>
#include <string>

// Student Code Area - Implement these functions to complete the tasks
// DO NOT modify the function signatures

// Task 1: Pointer arithmetic with void pointers and casts
void* advanceVoidPointer(void* ptr, int bytes);

// Task 2: Pointer arithmetic with different integer types
int* castAndAdvance(char* ptr, int offset);

// Task 3: Multi-dimensional array traversal with pointer arithmetic
// Traverse a 2D array using pointer arithmetic and return the sum of diagonal elements
int traverse2DArrayDiagonal(int** array2D, int rows, int cols);

// Task 4: Bit manipulation with pointer arithmetic
// Set specific bits in a uint32_t array using pointer arithmetic
void setBitsInArray(uint32_t* array, size_t size, uint32_t bitMask, size_t startIndex);

// Task 5: String manipulation with pointer arithmetic
// Reverse a string in-place using pointer arithmetic
void reverseStringInPlace(char* str);

// Task 6: Memory layout analysis with pointer arithmetic
// Analyze memory layout of a struct and extract specific fields
struct MemoryLayoutStruct
{
    uint8_t flags;
    uint16_t id;
    uint32_t value;
    uint64_t timestamp;
};

uint32_t extractValueFromMemoryLayout(const void* memoryPtr, size_t offset);

// Task 7: Function pointer table traversal
// Traverse an array of function pointers and execute them
typedef int (*MathFunction)(int, int);
int executeFunctionTable(MathFunction* funcTable, int size, int a, int b);

// Task 8: First set bit search in uint32_t array
// Find the first set bit in an array of uint32_t and return the byte index from start
size_t findFirstSetBitIndex(const uint32_t* array, size_t size);

// Task 9: Basic pointer-to-pointer assignment
void assignValueThroughPointer(int** ptrToPtr, int value);

// Task 10: Search for pointer with specific bits set in array of pointers
// Search through an array of pointers to uint32_t and find one that points to a value with specific bits set
// Return the index of the found pointer and the other bits that are set in that value
bool findPointerWithBitsSet(uint32_t** pointerArray,
                            size_t size,
                            uint32_t requiredBits,
                            size_t* foundIndex,
                            uint32_t* otherBitsSet);

// Task 11: Swap pointers using pointer-to-pointer
void swapPointers(int** ptr1, int** ptr2);

// Task 12: Return multiple values through pointer-to-pointer
void getMinMax(int arr[], int size, int** minPtr, int** maxPtr);

// Task 13: Pointer-to-pointer with struct
struct Node
{
    int data;
    Node* next;
};

void insertNodeAtBeginning(Node** head, int value);

// Task 14: Complex pointer-to-pointer linked list manipulation
// Given a pointer to a pointer to the head of a linked list, reverse the list in-place
// and return the number of nodes processed
struct ListNode
{
    int value;
    ListNode* next;
};

int reverseLinkedList(ListNode** head);

// Task 15: Pointer-to-pointer dynamic array management
// Implement a dynamic array that grows by doubling capacity when full
// Use pointer-to-pointer to manage the array pointer
struct DynamicArray
{
    int* data;
    size_t size;
    size_t capacity;
};

bool addToDynamicArray(DynamicArray** array, int value);

// Task 16: Complex pointer-to-pointer matrix manipulation
// Implement a function that manages a 2D matrix through pointer-to-pointer
// The function should transpose the matrix in-place using pointer arithmetic
struct Matrix2D
{
    int** data;
    size_t rows;
    size_t cols;
};

bool transposeMatrixInPlace(Matrix2D** matrix);

// Task 17: Extract wstring from vector<uint8_t>
std::wstring extractWStringFromVector(const std::vector<uint8_t>& data, size_t offset);

// Task 18: Create vector<uint8_t> from uint32_t
std::vector<uint8_t> createVectorFromUint32(uint32_t value);

// Task 19: Extract uint32_t from vector<uint8_t>
uint32_t extractUint32FromVector(const std::vector<uint8_t>& data, size_t offset);

// Task 20: Create vector<uint8_t> from POD struct
struct PODStruct
{
    uint16_t id;
    uint32_t value;
    uint8_t flags;
};

std::vector<uint8_t> createVectorFromPOD(const PODStruct& pod);

// Task 21: Extract POD struct from vector<uint8_t>
PODStruct extractPODFromVector(const std::vector<uint8_t>& data, size_t offset);

// Task 22: Convert vector<uint8_t> to vector<uint32_t>
std::vector<uint32_t> convertToUint32Vector(const std::vector<uint8_t>& data);

// Task 23: Convert vector<uint32_t> to vector<uint8_t>
std::vector<uint8_t> convertToUint8Vector(const std::vector<uint32_t>& data);

// Task 24: Insert wstring into vector<uint8_t> at offset
void insertWStringIntoVector(std::vector<uint8_t>& data, const std::wstring& str, size_t offset);

// Task 25: Complex vector data structure with variable-length fields
// Extract data from a complex vector structure with multiple variable-length fields
struct VectorDataHeader
{
    uint32_t magic;
    uint16_t version;
    uint16_t fieldCount;
    uint32_t totalSize;
};

struct VectorDataField
{
    uint8_t fieldType;
    uint8_t fieldFlags;
    uint16_t fieldId;
    uint32_t fieldOffset;
    uint32_t fieldLength;
};

std::vector<uint8_t> extractVectorDataField(const std::vector<uint8_t>& data, uint16_t fieldId);

// Task 26: Multi-dimensional vector manipulation with pointer arithmetic
// Convert a 1D vector to a 2D matrix representation using pointer arithmetic
struct VectorMatrix
{
    std::vector<uint32_t> data;
    size_t rows;
    size_t cols;
};

bool convertVectorToMatrix(const std::vector<uint32_t>& data, size_t rows, size_t cols, VectorMatrix** matrix);

// Task 27: Complex vector serialization with nested structures
// Serialize a complex nested structure into a vector<uint8_t> with proper alignment
struct NestedStruct
{
    uint32_t id;
    uint16_t flags;
    uint8_t type;
    uint8_t reserved;
    std::vector<uint32_t> data;
};

std::vector<uint8_t> serializeNestedStruct(const NestedStruct& nested);

// Task 28: Vector-based binary tree serialization
// Serialize a binary tree structure into a vector<uint8_t> using pointer arithmetic
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

std::vector<uint8_t> serializeBinaryTree(const BinaryTreeNode* root);
BinaryTreeNode* deserializeBinaryTree(const std::vector<uint8_t>& data);

// Task 29: Complex vector data encryption
// Implement a simple XOR encryption using vector<uint8_t> with pointer arithmetic
struct EncryptedData
{
    std::vector<uint8_t> data;
    uint32_t key;
    uint32_t checksum;
};

EncryptedData encryptVectorData(const std::vector<uint8_t>& data, uint32_t key);
std::vector<uint8_t> decryptVectorData(const EncryptedData& encrypted, uint32_t key);

// Complex struct with nested data (used by multiple tasks)
// Note: Variable length data follows immediately after this struct in memory
struct ComplexStruct
{
    uint32_t header;
    uint16_t flags;
    uint8_t dataType;
    uint32_t dataOffset;
    uint32_t dataLength;
    uint8_t padding[4];
};

// Task 30: Extract wstring from complex struct at data offset
std::wstring extractWStringFromComplexStruct(const ComplexStruct* structPtr);

// Task 31: Extract raw data from complex struct with length validation
std::vector<uint8_t> extractRawDataFromComplexStruct(const ComplexStruct* structPtr);

// Task 32: Extract wstring from nested struct traversal
std::wstring extractWStringFromNestedStruct(const void* basePtr, uint32_t structOffset);

// Task 33: Extract variable length data with offset calculation
std::vector<uint8_t> extractVariableLengthData(const void* basePtr, uint32_t dataOffset, uint32_t dataLength);

// Task 34: Fix incorrect pointer type causing wrong data copy
// TODO: Find and fix the bug in copyDataFromBuffer function
void copyDataFromBuffer(uint8_t* destination, const uint8_t* source, size_t offset, size_t length);

// Task 35: Fix wrong pointer offset in pointer-to-pointer scenario
// TODO: Find and fix the bug in readDataWithOffset function
uint32_t readDataWithOffset(uint32_t** dataPtr, size_t offset);

// Task 36: Fix incorrect dereferencing of uint8_t* to uint32_t
// TODO: Find and fix the bug in readUint32FromBuffer function
uint32_t readUint32FromBuffer(const uint8_t* buffer, size_t offset);

// Complex data structures for advanced bug-fixing tasks
struct DataHeader
{
    uint32_t magic;
    uint16_t version;
    uint16_t flags;
    uint32_t dataSize;
    uint32_t checksum;
};

struct DataBlock
{
    uint32_t blockId;
    uint16_t blockType;
    uint16_t reserved;
    uint32_t offset;
    uint32_t length;
    uint8_t* dataPtr;
};

struct ProcessingContext
{
    DataHeader* header;
    DataBlock* blocks;
    uint32_t blockCount;
    uint8_t* buffer;
    size_t bufferSize;
    uint32_t currentOffset;
    bool isValid;
};

// Task 37: Fix complex struct traversal and pointer arithmetic bug
// TODO: Find and fix the bug in the struct traversal logic
bool traverseDataStructure(const void* basePtr, uint32_t structureSize, uint32_t* resultCount, uint32_t** results);
bool validateStructureIntegrity(const DataHeader* header, const DataBlock* blocks, uint32_t count);
uint32_t* extractDataPointers(const DataBlock* blocks, uint32_t count, uint32_t* pointerCount);
bool processDataPointers(uint32_t* pointers, uint32_t count, uint32_t* results);

// Task 38: Fix complex memory management and pointer validation bug
// TODO: Find and fix the bug in the memory management system
bool allocateProcessingContext(ProcessingContext** context, size_t bufferSize);
bool initializeDataBlocks(ProcessingContext* context, uint32_t blockCount);
bool validateMemoryLayout(const ProcessingContext* context);
bool cleanupProcessingContext(ProcessingContext* context);
