// Siaod.Kr.Z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    Node* Left = NULL;
    Node* Right = NULL;
    Node* Parent = NULL;
    int Value = NULL;

};

/// Вставка нового значения
void SetValue(Node** p_rootNode, int value)
{
    // Получение левого или правого потомка
    Node* nextNode = value < (*p_rootNode)->Value ? (*p_rootNode)->Left : (*p_rootNode)->Right;

    // Если потомок не пуст, перейти к его потомкам
    if (nextNode != NULL)
    {
        SetValue(&nextNode, value);
        return;
    }

    // Если потомок пуст, создать его

    if (value < (*p_rootNode)->Value)
    {
        (*p_rootNode)->Left = new Node();
        (*p_rootNode)->Left->Value = value;
        (*p_rootNode)->Left->Parent = (*p_rootNode);

    }
    else
    {
        (*p_rootNode)->Right = new Node();
        (*p_rootNode)->Right->Value = value;
        (*p_rootNode)->Right->Parent = (*p_rootNode);
    }
}

/// Поиск узла
Node* FindNode(Node** p_rootNode, int value)
{
    if (value == (*p_rootNode)->Value)
        return (*p_rootNode);

    // Если удаляемого значения в дереве нет
    if ((*p_rootNode)->Left == NULL && (*p_rootNode)->Right == NULL)
        return NULL;

    // Получение левого или правого потомка
    Node* nextNode = value < (*p_rootNode)->Value ? (*p_rootNode)->Left : (*p_rootNode)->Right;

    // Если потомок не пуст, перейти к его потомкам
    if (nextNode != NULL)
        return FindNode(&nextNode, value);

    return NULL;
}

// Удаление значения
void DelValue(Node** p_rootNode, int value)
{
    // Если удаляется не текущий узел
    if (value != (*p_rootNode)->Value)
    {
        // Если удаляемого значения в дереве нет
        if ((*p_rootNode)->Left == NULL && (*p_rootNode)->Right == NULL)
            return;

        Node* nextNode = value < (*p_rootNode)->Value ?
                         ((*p_rootNode)->Left != NULL? (*p_rootNode)->Left : (*p_rootNode)->Right) : 
                         ((*p_rootNode)->Right != NULL? (*p_rootNode)->Right : (*p_rootNode)->Left);

        DelValue(&nextNode, value);
        return;
    }

    // Если узел - единственный в дереве
    if ((*p_rootNode)->Right == NULL && (*p_rootNode)->Left == NULL && (*p_rootNode)->Parent == NULL)
    {
        (*p_rootNode) = NULL;
        return;
    }

    // Если узел - лист
    if ((*p_rootNode)->Right == NULL && (*p_rootNode)->Left == NULL)
    {
        // Отсоединение от предка
        if ((*p_rootNode) == (*p_rootNode)->Parent->Left)
            (*p_rootNode)->Parent->Left = NULL;
        else
            (*p_rootNode)->Parent->Right = NULL;
        return;
    }

    // Если узел - корень дерева и имеет только левого потомка
    if ((*p_rootNode)->Right == NULL && (*p_rootNode)->Left != NULL && (*p_rootNode)->Parent == NULL)
    {
        (*p_rootNode)->Value = (*p_rootNode)->Left->Value;
        (*p_rootNode)->Left = (*p_rootNode)->Left->Left;
        return;
    }

    // Если узел имеет только левого потомка
    if ((*p_rootNode)->Right == NULL && (*p_rootNode)->Left != NULL)
    {
        // Присоединение к предку левого потомка
        (*p_rootNode)->Parent->Left = (*p_rootNode)->Left;
        return;
    }

    // Поиск ближайшего большего значения
    Node* currentNode = (*p_rootNode)->Right;
    while (currentNode->Left != NULL)
        currentNode = currentNode->Left;

    // Замена узла
    (*p_rootNode)->Value = currentNode->Value;
    
    // Если новый узел - не лист
    if (currentNode->Right != NULL)
    {
        currentNode->Parent->Right = currentNode->Right;
        return;
    }

    if (currentNode == currentNode->Parent->Left)
        currentNode->Parent->Left = NULL;
    else
        currentNode->Parent->Right = NULL;
}
 
/// Прямой обход дерева
void NLR(Node* rootNode)
{
    if (rootNode == NULL)
        return;

    // Вывод значения
    cout << rootNode->Value << " ";

    // Обход левой ветки
    if (rootNode->Left != NULL)
        NLR(rootNode->Left);

    // Обход правой ветки
    if (rootNode->Right != NULL)
        NLR(rootNode->Right);
}

///  Обратный обход дерева
void LRN(Node* rootNode)
{
    if (rootNode == NULL)
        return;

    // Обход левой ветки
    if (rootNode->Left != NULL)
        LRN(rootNode->Left);

    // Обход правой ветки
    if (rootNode->Right != NULL)
        LRN(rootNode->Right);

    // Вывод значения
    cout << rootNode->Value << " ";

}

/// Симметричный обход дерева
void LNR(Node* rootNode)
{
    if (rootNode == NULL)
        return;

    // Обход левой ветки
    if (rootNode->Left != NULL)
        LNR(rootNode->Left);

    // Вывод значения
    cout << rootNode->Value << " ";

    // Обход правой ветки
    if (rootNode->Right != NULL)
        LNR(rootNode->Right);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите числа и завершите пробелом с точкой: " << endl;

    // Ввод значений
    vector<int> values;
    string c_value = " ";
    while (true)
    {
        cin >> c_value;

        if (c_value == ".") 
            break;

        values.push_back(stoi(c_value));
    }

    // Проверка на пустоту списка
    if (values.empty())
        return 0;

    // Заполнение дерева
    Node* rootNode = new Node();
    rootNode->Value = values.front();
    values.erase(values.begin());

    Node** p_rootNode = &rootNode;
    for (auto value : values)
    {
        SetValue(p_rootNode, value);
    }

    cout << "\nПрямой обход дерева: " << endl;
    NLR(rootNode);
    cout << "\nОбратный обход дерева: " << endl;
    LRN(rootNode);
    cout << "\nСимметричный обход дерева: " << endl;
    LNR(rootNode);

    int n;
    cout << "\n\nВведите удаляемое значение: ";
    cin >> n;
    DelValue(p_rootNode, n);
    cout << "Прямой обход дерева после удаления значения: " << endl;
    NLR(rootNode);

    cout << "\n\nВведите значение для поиска: ";
    cin >> n;
    cout << (FindNode(p_rootNode, n) != NULL ? "Такое значение в дереве есть" : "Такого значения в дереве нет") << endl;

    return 0;
}
