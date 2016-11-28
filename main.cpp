#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

struct ListNode {
    int val;
    std::shared_ptr<ListNode> next;
    ListNode(int v, const std::shared_ptr<ListNode> & nx = nullptr)
        : val(v), next(nx) {}

    void print() {
        std::cout << val
                  << " -> "
                  << (next == nullptr ? "null\n":"");
    }
};

using pNode=std::shared_ptr<ListNode>;

pNode createList(const std::vector<int> & nums) {
    pNode head = nullptr;
    std::for_each(nums.rbegin(), nums.rend(),
                  [&](int n){
                      head = std::make_shared<ListNode>(n, head);
                  });
    return head;
}

void printList(const pNode & head) {
    if (head != nullptr) {
        head->print();
        printList(head->next);
    }
}

class solution {
  public:
    pNode partition(const pNode & head, int x) {

        return nullptr;
    }
};

int main() {
    std::vector<int> nums{1,4,3,2,5,2};
    int x = 3;
    pNode head = createList(nums);
    std::cout << "Before partitioning:\n";
    printList(head);

    solution soln;
    pNode newhead = soln.partition(head, x);
    std::cout << "After partitioning:\n";
    printList(newhead);
}
