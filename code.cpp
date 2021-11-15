//////////////////////////////////Iterative/(Written by me)/////////////////////////////////

 Node* flatten(Node* head) {
        Node *temp=head;
        while(temp)
        {
            Node *curr=temp;
            if(temp->child)
            {
                temp->child->prev=temp;
                Node *temp2=temp->next;
                temp->next=temp->child;
                temp->child=NULL;
                while(temp->next)
                    temp=temp->next;
                temp->next=temp2;
                if(temp2)
                    temp2->prev=temp;
            }
            
            temp=curr->next;
        }
        return head;
    }
    
    //////////////////////Recursive(By other person)///////////////////////////////////////
    
     Node* flatten(Node* head) {
        if(head) flatten_rec(head);
        return head;
    }
    
    Node* flatten_rec(Node* head){
        Node* curr = head;
        Node* tail = head;
        while(curr){
            Node* child = curr->child;
            Node* next = curr->next;
            if(child){
                Node* _tail = flatten_rec(child);
                _tail->next = next;
                if(next) next->prev = _tail;
                curr->next = child;
                curr->child = nullptr;
                child->prev = curr;
                curr = _tail;
            }
            else
                curr = next;
            if(curr) tail = curr;
        }
        return tail;
    }
