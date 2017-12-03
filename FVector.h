//
// Created by lex on 12.11.17.
//

#ifndef NEURO_0_0_FVECTOR_H
#define NEURO_0_0_FVECTOR_H

#include <vector>

/**
 * This class provides basic overloads for arithmetic operators.
 * The implementation is quite simplistic - no optimizations, intrinsics and other mad stuff like that.
 * Operations + - * / are pairwise, use ^ for dot-product.
 */

class FVector : public std::vector<float> {
public:
    FVector(size_type __n, const allocator_type& __a = allocator_type()) : vector(__n, 0.0f, __a) {};
    FVector(size_type __n, const value_type& __value,
            const allocator_type& __a = allocator_type()) : vector(__n, __value, __a) {};
    FVector(std::initializer_list<float> v) : vector(v){};


    FVector operator+(float val) const {
        FVector result(size());
        for (int i=0; i<size(); i++){
            result[i] = (*this)[i] + val;
        }
        return result;
    }

    FVector operator-(float val) const {
        FVector result(size());
        for (int i=0; i<size(); i++){
            result[i] = (*this)[i] - val;
        }
        return result;
    }

    FVector operator*(float val) const {
        FVector result(size());
        for (int i=0; i<size(); i++){
            result[i] = (*this)[i] * val;
        }
        return result;
    }

    FVector operator/(float val) const {
        FVector result(size());
        for (int i=0; i<size(); i++){
            result[i] = (*this)[i] / val;
        }
        return result;
    }

    FVector operator+(const FVector& op) const {
        FVector result(size());
        for (int i=0; i<size(); i++){
            result[i] = (*this)[i] + op[i];
        }
        return result;
    }

    FVector operator-(const FVector& op) const {
        FVector result(size());
        for (int i=0; i<size(); i++){
            result[i] = (*this)[i] - op[i];
        }
        return result;
    }

    FVector operator*(const FVector& op) const {
        FVector result(size());
        for (int i=0; i<size(); i++){
            result[i] = (*this)[i] * op[i];
        }
        return result;
    }

    FVector operator/(const FVector& op) const {
        FVector result(size());
        for (int i=0; i<size(); i++){
            result[i] = (*this)[i] / op[i];
        }
        return result;
    }

    float operator^(const FVector& op){
        float sum = 0.0f;
        for (int i=0; i<size(); i++){
            sum += (*this)[i] * op[i];
        }
        return sum;
    }

};


#endif //NEURO_0_0_FVECTOR_H
