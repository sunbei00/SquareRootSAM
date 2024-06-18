//
// Created by KwonSungMin on 2024-06-06.
//

#ifndef SQUAREROOTSAM_CPP_FACTORBASE_H
#define SQUAREROOTSAM_CPP_FACTORBASE_H
#include <Utils.h>

class FactorBase {
public:
    FactorBase(uInt fromNode, uInt toNode);
    virtual ~FactorBase();
    virtual Eigen::VectorX<Float> getResidual() = 0;
    virtual Eigen::MatrixX<Float> getJacobian() = 0;
    virtual uInt getDimension() = 0;
    uInt getId();
    uInt getFromNode();
    uInt getToNode();


protected:
    uInt id;
    uInt fromNode;
    uInt toNode;
    Eigen::MatrixX<Float> informationMatrix;
    static std::unordered_map<uInt, FactorBase*> idMapping; // 그래도 쓸건지 안쓸 건지 고민해 보기, Node만 쓰면 되지 않는지.
private:
    static uInt nextId;
    static void setNextId(FactorBase* factor);
};




template <int dim>
class Factor : public FactorBase {
public:
    Factor(uInt fromNode, uInt toNode, Eigen::MatrixX<Float> informationMatrix);
    void setInformationMatrix(Eigen::MatrixX<Float>);
    uInt getDimension() override;

protected:
    Eigen::Matrix<Float,1,dim> measurement;
};





template<int dim>
uInt Factor<dim>::getDimension() {
    return dim;
}

template<int dim>
void Factor<dim>::setInformationMatrix(Eigen::MatrixX<Float> informationMatrix) {
    if(dim*dim != informationMatrix.size())
        throw std::runtime_error("FactorRelativeError2D, setInformationMatrix() - mismatch dim");
    this->informationMatrix = informationMatrix;
}

template<int dim>
Factor<dim>::Factor(uInt fromNode, uInt toNode, Eigen::MatrixX<Float> informationMatrix) : FactorBase(fromNode,toNode){
    setInformationMatrix(informationMatrix);
}





#endif //SQUAREROOTSAM_CPP_FACTORBASE_H
