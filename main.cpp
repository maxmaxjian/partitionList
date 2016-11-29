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
	// solution 1
	// pNode newhead = head;
	// pNode curr, firstLarge;
	// curr = newhead;
	// firstLarge = curr;
	// while (curr != nullptr) {
	//     if (curr->val < x) {
	// 	if (curr != firstLarge) {
	// 	    std::swap(curr->val, firstLarge->val);
	// 	}
	// 	curr = curr->next;
	// 	firstLarge = firstLarge->next;
	//     }
	//     else
	// 	curr = curr->next;
	// }
        // return newhead;

	// solution 2
	pNode newhead = nullptr;
	if (head != nullptr) {
	    if (head->val < x) {
		newhead = head;
		newhead->next = partition(newhead->next, x);
	    }
	    else {
		pNode p = head, prev = nullptr;
		while (p != nullptr && p->val >= x) {
		    prev = p;
		    p = prev->next;
		}
		if (p != nullptr) {
		    newhead = p;
		    prev->next = p->next;
		    newhead->next = partition(head, x);
		}
		else
		    newhead = head;
	    }
	}
	return newhead;
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
