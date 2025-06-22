#include <iostream>

void towerOfHanoi(int disks, char source, char helper, char destination)
{
    if (disks == 1)
    {
        std::cout << "Disk 1 moved from " << source << " to " << destination << std::endl;
        return;
    }

    // If more than 1 disk move the (n-1) disk to the helper disk

    towerOfHanoi(disks - 1, source, destination, helper);

    std::cout << "Disk " << disks << " moved from " << source << " to " << destination << std::endl;

    // Then move (n-2) disk to helper to destination

    towerOfHanoi(disks - 1, helper, source, destination);

    // std::cout << "Disk moved from " << helper << " to " << destination << std::endl;
}

int main()
{
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}