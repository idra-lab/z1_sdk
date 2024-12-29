#ifndef MATHTYPES_COMMONS_H
#define MATHTYPES_COMMONS_H

/************************/
/****** Functions *******/
/************************/
inline Vec34 vec12ToVec34(Vec12 vec12){
    Vec34 vec34;
    for(int i(0); i < 4; ++i){
        vec34.col(i) = vec12.segment(3*i, 3);
    }
    return vec34;
}

inline Vec12 vec34ToVec12(Vec34 vec34){
    Vec12 vec12;
    for(int i(0); i < 4; ++i){
        vec12.segment(3*i, 3) = vec34.col(i);
    }
    return vec12;
}

template<typename T>
inline VecX stdVecToEigenVec(T stdVec){
    VecX eigenVec = Eigen::VectorXd::Map(&stdVec[0], stdVec.size());
    return eigenVec;
}

inline std::vector<double> EigenVectostdVec(VecX eigenVec){
    std::vector<double> stdVec;
    for(int i(0); i<eigenVec.size();i++){
        stdVec.push_back(eigenVec(i));
    }
    return stdVec;
}

#endif  // MATHTYPES_H
