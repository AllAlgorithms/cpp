#include <iostream>

using namespace std;



struct btNode
{
   int data;
   btNode* left;
   btNode* right;
};






void bst_insert(btNode*& bst_root, int anInt)
{
   if(bst_root == 0) // if list is empty
   {
      btNode* newNode = new btNode;
     
      newNode->data = anInt;
      newNode->left = 0;
      newNode->right= 0;
     
      bst_root = newNode;
      return;  // end function call
   }

   btNode* marker = new btNode; // traverse pointer
   marker = bst_root;  

   while( marker != 0) // not at a leaf
   { 
      if(marker->data == anInt) // if duplicate is found
      {
         marker->data = anInt; // overwrite and leave function
         return;
      }


   
      if(marker->data > anInt) // if # is less than
      {  
         if(marker->left != 0)
         {
            marker = marker->left; // if not empty move left
         }
   
          else  // if empty, populate
          {
             btNode* newNode = new btNode; // create
             
             newNode->data = anInt;  // populate
             newNode->left = 0;
             newNode->right = 0;
             
             marker->left = newNode;  // attach
             return; 

          }
       }

       if(marker->data < anInt) // if # is greater
       {
          if(marker->right != 0)
             marker = marker->right;
           
          else 
          {
             btNode* newNode = new btNode;
       
             newNode->data = anInt;
             newNode->left = 0;
             newNode->right = 0;
      
             marker->right = newNode;
             return;  
         }
       
       } 
     
   }
}


 bool bst_remove(btNode*& bst_root, int anInt)
 {
     
      if(bst_root == 0) // if empty tree return false
         return false;
                
                  
      if(bst_root->data > anInt) // if # is less than 
         return bst_remove(bst_root->left,anInt); // shift and recurse 
                              
      if(bst_root->data < anInt) // if # is greater than
         return bst_remove(bst_root->right,anInt);
                                         

      if(bst_root->data == anInt) // if # is found
      {
         if(bst_root->left == 0) // if no left node
            { 
               btNode* temp = bst_root; //mini remove max 
                                                                    
               bst_root = bst_root->right;

               delete temp;
               return true;
            }
                                                                                                            
                 // if left node is occupied  
         bst_remove_max(bst_root->left, bst_root->data);
            return true;
      }

   return false; // if nothing is found 

   }
      
 void bst_remove_max(btNode*& bst_root, int& info)
 { 

     if(bst_root->right != 0) // if right node is still occupied 
        return bst_remove_max(bst_root->right, info);
                                                                                                                                           

     btNode* tempNode = new btNode; // prepare node to be deleted
        tempNode = 0; // make NULL

     btNode* marker = new btNode; // make a node to traverse tree
        marker = bst_root;
                                                                                                                                                                        

     if(bst_root->right == 0) // if at rightmost node
        {
           info = bst_root->data; // get information stored in node
                                                                                                                                                                                          
           tempNode = marker;
                                                                                                                                                                                                    
           bst_root = bst_root->left;

           delete tempNode;    
        }
                                                                                                                                                                                                           
 }

