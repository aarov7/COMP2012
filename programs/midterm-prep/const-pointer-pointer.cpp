int main() {
// A pointer to a pointer to a const int
const int** ptr1 = new int*; /* Error: Yes */
// A const pointer to a pointer to an int
int** const ptr2 = new int*; /* Error: No */
// A pointer to a pointer to a const int
const int** ptr3 = new const int*; /* Error: No */
// A pointer to a pointer to a const int
const int** ptr4 = new int const*; /* Error: No */
// A pointer to a pointer to a const int
const int** ptr5 = new int* const; /* Error: Yes */
// To evaluate the correctness of the following statements, you may
// assume that the incorrect statements (if any) are fixed so that all
// pointer variables declared above are correctly allocated.
*ptr1 = new int;
**ptr1 = 1; /* Error: Yes */
*ptr2 = new int;
**ptr2 = 2; /* Error: No */
*ptr3 = new int;
**ptr3 = 3; /* Error: Yes */
*ptr4 = new int;
**ptr4 = 4; /* Error: Yes */
*ptr5 = new int;
**ptr5 = 5; /* Error: Yes */
// Assume memory de-allocations are purposely not done here.
return 0;
}
