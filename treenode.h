#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> child;

    TreeNode(T data)
    {
        this->data = data;
    }

    //destructor gets called by delete word;
    //delete root ; will delete whole tree;

    ~TreeNode(){
        for (int i = 0; i < child.size(); i++)
        {
            delete child[i];
        }
        
    }
};

template <typename T>

void printTree(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        cout << front->data << " : ";
        for (int i = 0; i < front->child.size(); i++)
        {
            cout << front->child[i]->data << " ";
            q.push(front->child[i]);
        }
        q.pop();
        cout << endl;
    }

    cout << endl;
}

TreeNode<int> *takeInput()
{
    cout << "Enter data:" << endl;
    int rootdata;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    cout << "How many childs " << rootdata << " has: " << endl;
    long long int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "For child " << i + 1 << " of " << rootdata << " : " << endl;
        TreeNode<int> *child = takeInput();
        root->child.push_back(child);
    }

    return root;
}

TreeNode<int> *takeInputLevelWise()
{

    cout << "Enter data:" << endl;
    int rootdata;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);

    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();
        cout << "Enter number of childs of " << front->data << endl;
        long long int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter data of child " << i + 1 << " of " << front->data << " : " << endl;
            long long int childdata;
            cin >> childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            q.push(child);
            front->child.push_back(child);
        }
    }

    return root;
}

int totalNodes(TreeNode<int> *root)
{
    if (root==nullptr)
    {
        return 0;
    }
    
    int totalnodes = 0;
    for (int i = 0; i < root->child.size(); i++)
    {
        totalnodes += totalNodes(root->child[i]);
    }
    return totalnodes + 1;
}

int height(TreeNode<int> *root)
{
    if (root==nullptr)
    {
        return 0;
    }

    if (root->child.size() == 0)
    {
        return 1;
    }
    int maxx = 0;
    for (int i = 0; i < root->child.size(); i++)
    {
        maxx = max(height(root->child[i]), maxx);
    }
    return maxx + 1;
}

void printNodesAtDepth(TreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->child.size(); i++)
    {
        printNodesAtDepth(root->child[i], k - 1);
    }
}

int totalLeafNodes(TreeNode<int>*root){
    if (root==nullptr)
    {
        return 0;
    }
    int totalleafnodes=0;
    if (root->child.size()==0){
        return 1;
    }
    
    for (int i = 0; i < root->child.size(); i++)
    {
        totalleafnodes+=totalLeafNodes(root->child[i]);
    }
    return totalleafnodes;
    
}

void preorder(TreeNode<int>*root){
    if (root==nullptr)
    {
        return;
    }
    cout<<root->data<<" ";
    for (int i = 0; i < root->child.size(); i++)
    {
        preorder(root->child[i]);
    }
    
}
//we must delete tree at end as we made it dynamically;
//by one way given below, another way is by using destructor;
//when we use delete root; destructor gets called.
void deleteTree(TreeNode<int>*root){
    for (int i = 0; i < root->child.size(); i++)
    {
       deleteTree(root->child[i]);
    }
    delete root;
}