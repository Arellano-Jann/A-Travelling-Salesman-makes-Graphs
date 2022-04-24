// protected

// cop //
template <typename T>
int Graph<T>::getLabelIndex(T label) const{
    int index = -1;
    for (int i = 0; i < labels.size(); i++){
        if(labels[i] == label){
            index = i;
            break;
        }
    }
    return index;
}

// cop
template <typename T>
void Graph<T>::depthTraversalHelper(T label, void visit(T&), bool* seen_arr, std::stack<T>& label_stack){
    int index = getLabelIndex(label);
    if (index == -1) return;
    if (seen_arr[index]) return; // bool pointer index???

    seen_arr[index] = true; // ??? don't think that this is right
    visit(label);
    for (int i = 0; i < adjacencyMatrix[index].size(); i++){
        if(adjacencyMatrix[index][i] != INT_MAX){
            depthTraversalHelper(labels[i], visit, seen_arr, label_stack);
        }
    }
}

// cop
template <typename T>
void Graph<T>::breadthTraversalHelper(T label, void visit(T&), bool* seen_arr, std::queue<T>& label_queue){
    int index = getLabelIndex(label);
    if (index == -1) return;
    if (seen_arr[index]) return; // bool pointer index???

    seen_arr[index] = true; // ??? don't think that this is right
    visit(label);
    for (int i = 0; i < adjacencyMatrix[index].size(); i++){
        if(adjacencyMatrix[index][i] != INT_MAX){
            label_queue.push(labels[i]);
        }
    }
}

// public
template <typename T>
int Graph<T>::getNumVertices() const{ return vertexCount; }

template <typename T>
int Graph<T>::getNumEdges() const{ return edgeCount; }

template <typename T>
bool Graph<T>::add(T startLabel, T endLabel, int edgeWeight){
    int startIndex = getLabelIndex(startLabel);
    int endIndex = getLabelIndex(endLabel);
    // if (startIndex == -1 || endIndex == -1) return false; // label not found so exit
    if (startIndex == -1){
        vertexCount++;
        labels.push_back(startLabel);

        // resize matrix to hold new row and column
        adjacencyMatrix.resize(vertexCount);
        for(int i = 0; i < vertexCount; i++){
            adjacencyMatrix[i].resize(vertexCount, INT_MAX);
        }

        startIndex = vertexCount - 1;
        // adjacencyMatrix.resize(vertexCount, std::vector<int>(vertexCount, INT_MAX)); // trash implement
        // adjacencyMatrix.push_back(std::vector<int>(vertexCount, INT_MAX)); // trash implement
    } // label not found so it's made

    if (endIndex == -1){
        vertexCount++;
        labels.push_back(endLabel);

        // resize matrix to hold new row and column
        adjacencyMatrix.resize(vertexCount);
        for(int i = 0; i < vertexCount; i++){
            adjacencyMatrix[i].resize(vertexCount, INT_MAX);
        }

        endIndex = vertexCount - 1;
    } // label not found so it's made

    if (adjacencyMatrix[startIndex][endIndex] != INT_MAX) return false; //returns false if edge already exists
    adjacencyMatrix[startIndex][endIndex] = edgeWeight;
    edgeCount++;
    return true;
}

template <typename T>
bool Graph<T>::remove(T startLabel, T endLabel){
    int startIndex = getLabelIndex(startLabel);
    int endIndex = getLabelIndex(endLabel);
    if (startIndex == -1 || endIndex == -1) return false; // label not found so exit
    if (adjacencyMatrix[startIndex][endIndex] == INT_MAX) return false; // return false if edge doesn't exist
    adjacencyMatrix[startIndex][endIndex] = INT_MAX;
    edgeCount--;

    bool deleteStartIndex = true;
    bool deleteEndIndex = true;
    for (int i = 0; i < vertexCount; i++){
        // if (adjacencyMatrix[i][startIndex] != INT_MAX){ // might be this
        if (adjacencyMatrix[startIndex][i] != INT_MAX){
            deleteStartIndex = false;
            break;
        }
    }
    for (int i = 0; i < vertexCount; i++){
        // if (adjacencyMatrix[endIndex][i] != INT_MAX){ // might be this
        if (adjacencyMatrix[i][endIndex] != INT_MAX){
            deleteEndIndex = false;
            break;
        }
    }


    if (deleteStartIndex && deleteEndIndex){ // deletes row and column if both are empty  
        adjacencyMatrix.erase(adjacencyMatrix.begin() + startIndex);
        for (int i = 0; i < vertexCount; i++){
            adjacencyMatrix[i].erase(adjacencyMatrix[i].begin() + endIndex);
        }
        labels.erase(labels.begin() + startIndex);
        vertexCount--;
    }
    return true;
}

template <typename T>
int Graph<T>::getEdgeWeight(T startLabel, T endLabel){
    int startIndex = getLabelIndex(startLabel);
    int endIndex = getLabelIndex(endLabel);
    if (startIndex == -1 || endIndex == -1) return INT_MAX; // label not found so exit
    return adjacencyMatrix[startIndex][endIndex];
}

// cop
template <typename T>
void Graph<T>::depthFirstTraversal(T startLabel, void visit(T&)){
    bool* seen_arr = new bool[vertexCount];
    for (int i = 0; i < vertexCount; i++){
        seen_arr[i] = false;
    }
    std::stack<T> label_stack;
    depthTraversalHelper(startLabel, visit, seen_arr, label_stack);
    delete[] seen_arr;
}

// cop
template <typename T>
void Graph<T>::breadthFirstTraversal(T startLabel, void visit(T&)){
    bool* seen_arr = new bool[vertexCount];
    for (int i = 0; i < vertexCount; i++){
        seen_arr[i] = false;
    }
    std::queue<T> label_queue;
    breadthTraversalHelper(startLabel, visit, seen_arr, label_queue);
    delete[] seen_arr;
}

template <typename T>
void Graph<T>::printAdjecencyMatrix() const{
    for (int i = 0; i < vertexCount; i++){
        for (int j = 0; j < vertexCount; j++){
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Other implement" << std::endl;
    for (int i = 0; i < adjacencyMatrix.size(); i++){
        for (int j = 0; j < adjacencyMatrix[i].size(); j++){
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
std::vector<T> Graph<T>::getLabels() const{ return labels; }
