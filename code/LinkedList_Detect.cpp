/**
 * ¡¥±Ì◊∑∏œŒ Ã‚
 */
 #include <iostream>
 #include <cstdlib>

 using namespace std;

 struct Node
 {
     int value;
     Node * next;
 };

 void node_insert(Node *node1, Node *node2)
 {
     node2->next = node1->next;
     node1->next = node2;
 }

 Node* node_index(Node *head, int index)
 {
     Node *p = head;
     while(--index>=0 && (p=p->next) != NULL);

     if(index > 0) return NULL;
     return p;
 }

 void node_print(Node *head)
 {
     Node *p = head;
     int i = 0;
     while(p && i++<40)
     {
         cout<<p->value<<" ";
         p = p->next;
     }
     cout<<endl;
 }

 bool isCircle(Node *head, Node *& circleNode, Node *& lastNode)
 {
     lastNode = NULL;
     Node * fast = head->next;
     Node * slow = head;
     while(fast != slow && fast && slow)
     {
         if(fast->next != NULL) fast = fast->next;

         if(fast->next == NULL) lastNode = fast;
         if(slow->next == NULL) lastNode = slow;

         fast = fast->next;
         slow = slow->next;
     }

     if(fast == slow && fast && slow)
     {
         circleNode = fast;
         return true;
     }

     return false;
 }

 bool detect(Node* head1, Node* head2)
 {
     Node* circleNode1;
     Node* circleNode2;
     Node* lastNode1;
     Node* lastNode2;

     bool isCircled1 = isCircle(head1, circleNode1, lastNode1);
     bool isCircled2 = isCircle(head2, circleNode2, lastNode2);

     if(isCircled1 != isCircled2) return false;
     else if(!isCircled1 && !isCircled2) return lastNode1 == lastNode2;
     else
     {
         Node* temp = circleNode1->next;
         while(temp != circleNode1)
         {
             if(temp == circleNode2)
             {
                 cout<<"Detected node:"<<temp->value<<endl;
                 return true;
             }
             temp = temp->next;
         }
         return false;
     }

     return false;
 }

 unsigned int list_length(Node* head1)
 {
     Node* p = head1;
     int len = 0;
     while(p && ++len && (p=p->next)) ;
     return len;
 }

 Node* find_first_dectect_node(Node* head1, Node* head2)
 {
     unsigned int len1 = list_length(head1);
     unsigned int len2 = list_length(head2);
     int lenDiff = len1 - len2;

     Node* nodeLong = head1;
     Node* nodeShort = head2;
     if(len2 > len1)
     {
         lenDiff = len2 - len1;
         nodeLong = head2;
         nodeShort = head1;
     }

     while(lenDiff-->0 && (nodeLong=nodeLong->next));

     while(nodeLong != nodeShort && nodeLong && nodeShort)
     {
         nodeLong = nodeLong->next;
         nodeShort = nodeShort->next;
     }

     if(nodeLong == nodeShort) return nodeLong;

     return NULL;
 }

 int main()
 {
     Node *head = new Node;
     head->value = 0;
     head->next = NULL;

     for(int i=20; i>0; i--)
     {
         Node *node = new Node;
         node->value = i;
         node->next = NULL;
         node_insert(head, node);
     }
     //Node *node1 = node_index(head, 5);
     //Node *node2 = node_index(head, 20);
     //node2->next = node1;

     cout<<"head 1:";
     node_print(head);

     Node * circleNode;
     Node * lastNode = NULL;
     bool isCircled = isCircle(head, circleNode, lastNode);
     cout<<endl<<"Is head1 circle:"<<isCircled;
     if(isCircled) cout<<", circle node:"<<circleNode->value;
     if(!isCircled) cout<<", last node:"<<lastNode->value;
     cout<<endl<<endl;


     Node *head2 = new Node;
     head2->value = 100;
     head2->next = NULL;

     for(int i=130; i>100; i--)
     {
         Node *node = new Node;
         node->value = i;
         node->next = NULL;
         node_insert(head2, node);
     }
     cout<<"head 2:";
     node_print(head2);

     isCircled = isCircle(head2, circleNode, lastNode);
     cout<<endl<<"Is head2 circle:"<<isCircled;
     if(isCircled) cout<<", circle node:"<<circleNode->value;
     if(!isCircled) cout<<", last node:"<<lastNode->value;
     cout<<endl<<endl;

     Node *node3 = node_index(head2, 23);
     Node *node4 = node_index(head, 20);
     node4->next = node3;
     cout<<"New detect head 1:";
     node_print(head);

     bool isDetect = detect(head, head2);
     cout<<"Is head1 and head2 detect:"<<isDetect<<endl;

     unsigned int len = list_length(head);
     cout<<"head 1's length:"<<len<<endl;

     Node* node7 = find_first_dectect_node(head, head2);
     cout<<"First common node:"<<node7->value<<endl;

     return 0;
 }
