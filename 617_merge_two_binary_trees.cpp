#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* str2tree(string &s,int &index){
  int sign=1,value =0; 
  if(s[index] == '-' ){
    sign = -1; 
    index++;
  }
  while(index < s.length() && isdigit(s[index]) ){
    value = 10 * value + s[index] - '0';
    index ++; 
  }
  TreeNode *root = new TreeNode(sign * value);
  if( index < s.length() && s[index] == '('  ){  
    index++;
    root->left = str2tree(s,index);
    index++;
    if( index < s.length() && s[index] == '('  ){  
      index++;
      root->right = str2tree(s,index);
      index++;
    }   
  }
  return root;

}

TreeNode* str2tree(string s){
	if(s.length() == 0){
		return NULL;
	}
	int index = 0;
	return str2tree(s,index);
}


TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

	if(t1==NULL && t2==NULL){
		return NULL;
	}

	int t1_val,t2_val;
	TreeNode* t1_left = NULL;
	TreeNode* t1_right = NULL;
	TreeNode* t2_left = NULL;
	TreeNode* t2_right = NULL;
	if(t1){
		t1_val = t1->val;	
		if(t1->left){
			t1_left = t1->left;
		}
    if(t1->right){
      t1_right = t1->right;
    }  
	}else{
		t1_val = 0;
	}
  if(t2){
    t2_val = t2->val; 
    if(t2->left){
      t2_left = t2->left;
    }   
    if(t2->right){
      t2_right = t2->right;
    }
  }else{
    t2_val = 0;
  }   

	TreeNode* mergebranch = new TreeNode(t1_val+t2_val);
	if(t1_left || t2_left){
		mergebranch->left = mergeTrees(t1_left,t2_left);
	}
	if(t1_right || t2_right){
		mergebranch->right = mergeTrees(t1_right,t2_right);
	}

	return mergebranch;   
}


int main(){

	string str1 = "1(3(5))(2)";
	string str2 = "2(1()(4))(3()(7))";
  TreeNode* p1 = str2tree(str1);
  TreeNode* p2 = str2tree(str2);

	TreeNode* p = mergeTrees(p1,p2);
	cout << p->left->right->val << endl;
	//cout << p2->right->right->val << endl;
  //generate(pt);


	return 0;
}
