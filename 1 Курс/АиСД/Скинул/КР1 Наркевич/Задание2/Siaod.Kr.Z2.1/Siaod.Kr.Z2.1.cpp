#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {

    bool LIsThread = false;
    Node* Left = NULL;
    bool RIsThread = false;
    Node* Right = NULL;

    int Value = NULL;

};

void SetValue(Node** p_rootNode, int value)
{
    // Получение левого или правого потомка
    Node* nextNode = value < (*p_rootNode)->Value && !(*p_rootNode)->LIsThread ? (*p_rootNode)->Left:
                     value >= (*p_rootNode)->Value && !(*p_rootNode)->RIsThread ? (*p_rootNode)->Right:
                                                      NULL;
                                
    // Если потомок не пуст, перейти к его потомкам
    if (nextNode != NULL)
    {
        SetValue(&nextNode, value);
        return;
    }


    if (value < (*p_rootNode)->Value)
    {
        Node* newNode = new Node();
        newNode->Value = value;
        newNode->LIsThread = true;
        newNode->Left = (*p_rootNode)->Left;
        newNode->RIsThread = true;
        newNode->Right = (*p_rootNode);

        (*p_rootNode)->LIsThread = false;
        (*p_rootNode)->Left = newNode;

    }
    else
    {
        Node* newNode = new Node();
        newNode->Value = value;
        newNode->LIsThread = true;
        newNode->Left = (*p_rootNode);
        newNode->RIsThread = true;
        newNode->Right = (*p_rootNode)->Right;

        (*p_rootNode)->RIsThread = false;
        (*p_rootNode)->Right = newNode;
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

/// Поиск узла (на основе прошивки)
Node* FindThreatedNode(Node* rootNode, int value)
{
    // Начало обхода с корня дерева
    Node* currentNode = rootNode;

    while (true)
    {
        // Нахождение самого левого узла в поддереве
        while (currentNode->Left != NULL && !currentNode->LIsThread)
            currentNode = currentNode->Left;

        while (true)
        {
            // Возвращение найденного узла
            if (currentNode->Value == value)
                return currentNode;

            // Если правая нить ведет к корню дерева и имеет значение больше, чем корень, то достигнут конец списка
            if (currentNode->RIsThread && currentNode->Right == rootNode && currentNode->Value > currentNode->Right->Value)
                return NULL;

            // Если правая ссылка - нить, то перейти, иначе перейти и искать самый левый узел
            if (currentNode->RIsThread)
                currentNode = currentNode->Right;
            else
            {
                currentNode = currentNode->Right;
                break;
            }

        }

    }
}

/// Симметричный обход дерева
void LNR(Node* rootNode, vector<int>& values)
{
    // Обход левой ветки
    if (rootNode->Left != NULL  && !rootNode->LIsThread)
        LNR(rootNode->Left, values);

    // Сохранение значения
    values.push_back(rootNode->Value);

    // Обход правой ветки
    if (rootNode->Right != NULL && !rootNode->RIsThread)
        LNR(rootNode->Right, values);
}

/// Симметричный обход прошитого дерева
void ThreadedLNR(Node* rootNode)
{

    // Начало обхода с корня дерева
    Node* currentNode = rootNode;

    while (true)
    {
        // Нахождение самого левого узла в поддереве
        while (currentNode->Left != NULL && !currentNode->LIsThread)
            currentNode = currentNode->Left;

        while (true)
        {
            // Вывод узла
            cout << currentNode->Value << " ";

            // Если правая нить ведет к корню дерева и имеет значение больше, чем корень, то достигнут конец списка
            if (currentNode->RIsThread && currentNode->Right == rootNode && currentNode->Value > currentNode->Right->Value)
                return;

            // Если правая ссылка - нить, то перейти, иначе перейти и искать самый левый узел
            if (currentNode->RIsThread)
                currentNode = currentNode->Right;
            else
            {
                currentNode = currentNode->Right;
                break;
            }
            
        }
        
    }
}

/// Симметричная прошивка дерева
void LNRThread(Node** p_rootNode)
{
    // Получение значений дерева при симметричном обходе
    vector<int> values;
    LNR((*p_rootNode), values);

    // Проверка на пустоту списка
    if (values.empty())
        return;

    // Начало со второго значения и до предпоследнего
    for (int i = 1; i < values.size() - 2; i++)
    {
        // Получение указателя на узел с таким значением
        Node* currentNode = FindNode(p_rootNode, values[i]);

        // Если нет левого потомка, то указать нить на узел с предыдущим значением
        if (currentNode->Left == NULL)
        {
            currentNode->LIsThread = true;
            currentNode->Left = FindNode(p_rootNode, values[i - 1]);
        }

        // Если нет правого потомка, то указать нить на узел со следующим значением
        if (currentNode->Right == NULL)
        {
            currentNode->RIsThread = true;
            currentNode->Right = FindNode(p_rootNode, values[i + 1]);
        }
    }

    // Связь первого узла с корнем дерева, и, при отсутствии правого потомка, указать нить на узел со следующим значением
    Node* firstNode = FindNode(p_rootNode, values[0]);
    firstNode->LIsThread = true;
    firstNode->Left = (*p_rootNode);

    if (firstNode->Right == NULL)
    {
        firstNode->RIsThread = true;
        firstNode->Right = FindNode(p_rootNode, values[1]);
    }

    // Связь последнего узла с корнем дерева, и, при отсутствии левого потомка, указать нить на узел с предыдущим значением
    Node* lastNode = FindNode(p_rootNode, values[values.size() - 1]);
    lastNode->RIsThread = true;
    lastNode->Right = (*p_rootNode);

    if (lastNode->Left == NULL)
    {
        lastNode->LIsThread = true;
        lastNode->Left = FindNode(p_rootNode, values[values.size() - 2]);
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите числа, в конце точка: " << endl;

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

    LNRThread(p_rootNode);
    cout << "\nОбход прошитого дерева: " << endl;
    ThreadedLNR(rootNode);
    int n;
    cout << "\n\nВведите вставку: ";
    cin >> n;
    SetValue(p_rootNode, n);
    cout << "Обход дерева после вставки: " << endl;
    ThreadedLNR(rootNode);

    cout << "\n\nВведите значение для поиска: ";
    cin >> n;
    cout << (FindThreatedNode(rootNode, n) != NULL ? "Присутствует" : "Отсутствует") << endl;

    return 0;
}
