// Question Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next = NULL;
    }


};

class Solution {
    public:
        Node* insertAtTail(Node* &head, int val) {
            if (head == NULL) {
                head = new Node(val);
                return head;
            }

            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = new Node(val);
            return head;
        }

        Node* removeNodeFromList(Node* &head, Node* NodetoDelete) {
            if (head == NULL || NodetoDelete == NULL) {
                return head; // Nothing to delete
            }

            if (head == NodetoDelete && head->next == head) {
                // Only one node in the list
                delete head;
                head = NULL;
                return head;
            }

            if (head == NodetoDelete) {
                // If the node to delete is the head
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                Node* newHead = head->next;
                delete head;
                head = newHead; // Move head to the next node
                return head;
            }

            // For nodes other than the head
            Node* temp = head;
            while (temp->next != NodetoDelete) {
                temp = temp->next;
            }

            if (temp->next == NodetoDelete) {
                // cout<<"Node to delete: "<<NodetoDelete->value<<endl;
                head = NodetoDelete->next; // Update head to the next node
                temp->next = NodetoDelete->next;
                delete NodetoDelete;
            }

            return head;
        }

        
        void triverse(Node* &head){
            Node *temp = head;
            do{
            temp = temp->next;
            } 
            while (temp!=head);
        }

        int FindLastNodeRemaining(Node* &head, int jumps){
            while (head->next!=head)
            {
                Node* temp = head;
                for (int i = 0; i <jumps-1; i++)
                {
                    // cout<<"Pointer at: "<<temp->value<<endl;
                    temp = temp->next;
                    // cout<<"Pointer at: "<<temp->value<<endl;
                }
                // cout<<"Deleting: "<<temp->value<<endl;
                head = removeNodeFromList(head, temp);
                triverse(head);
            }
            // cout<<"Returning: "<<head->value<<endl;
            return head->value;
        }

        int findTheWinner(int n, int k) {
            //Vector of Nodes
            vector<Node*> Nodes = vector<Node*>();
            for (int i = 1; i <= n; i++)
            {
                Nodes.push_back(new Node(i));
            }
            for(int i=0;i<Nodes.size()-1;i++){
                Nodes[i]->next = Nodes[i+1];
            }
            Nodes[Nodes.size()-1]->next = Nodes[0];
            //IMP - Head of Circular LinkedList
            Node* head = Nodes[0];
            triverse(head);
            // cout<<"Jumps: "<<k<<endl;
            int res = FindLastNodeRemaining(head, k);
            cout<<"Answer: "<<res<<endl;
            return res; 
        }
};

int main() {
    Solution S = Solution();
    S.findTheWinner(123, 1);
    return 0;
}
