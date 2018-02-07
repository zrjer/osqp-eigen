/**
 * @file OptimizatorData.hpp
 * @author Giulio Romualdi
 * @copyright  Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 * @date 2018
 */

#ifndef OPTIMIZATOR_DATA_HPP
#define OPTIMIZATOR_DATA_HPP

// Eigen
#include <Eigen/Dense>

// OSQP
#include "osqp.h"

// OSQPWrapper
#include "SparseMatrix.hpp"

/**
 * OSQPWrapper namespace.
 */
namespace OSQPWrapper
{
    /**
     * OptimizatorData class is a wrapper of the OSQP OSQPData struct.
     */
    class OptimizatorData
    {
        OSQPData *m_data; /**< OSQPData struct. */
        bool m_isNumberOfVariablesSet; /**< Boolean true if the number of variables is set. */
        bool m_isNumberOfConstraintsSet; /**< Boolean true if the number of constraints is set. */
        bool m_isHessianMatrixSet;  /**< Boolean true if the hessian matrix is set. */
        bool m_isGradientSet; /**< Boolean true if the gradient vector is set. */
        bool m_isLinearConstraintsMatrixSet; /**< Boolean true if the linear constrain matrix is set. */
        bool m_isLowerBoundSet; /**< Boolean true if the lower bound vector is set. */
        bool m_isUpperBoundSet; /**< Boolean true if the upper bound vector is set. */

    public:
        /**
         * Constructor.
         */
        OptimizatorData();

        /**
         * Constructor.
         * @param n is the number of variables;
         * @param m is the number of constraints.
         */
        OptimizatorData(int n, int m);

        /**
         * Deconstructor.
         */
        ~OptimizatorData();

        /**
         * Set the number of variables.
         * @param n is the number of variables.
         */
        void setNumberOfVariables(int n);

        /**
         * Set the number of constraints.
         * @param m is the number of constraints.
         */
        void setNumberOfConstraints(int m);

        /**
         * Set the quadratic part of the cost function (Hessian).
         * It is assumed to be a simmetric matrix.
         * @param hessian is the Hessian matrix.
         * @return true/false in case of success/failure.
         */
        bool setHessianMatrix(const OSQPWrapper::SparseMatrix& hessian);

        /**
         * Set the linear part of the cost function (Gradient).
         * @param gradient is the Gradient vector.
         * @return true/false in case of success/failure.
         */
        template<int n>
        bool setGradient(Eigen::Matrix<c_float, n, 1>& gradien);

        /**
         * Set the linear constraints matrix A (size m x n)
         * @param A is the linear constraint matrix.
         * @return true/false in case of success/failure.
         */
        bool setLinearConstraintsMatrix(const OSQPWrapper::SparseMatrix& A);

        /**
         * Set the array for lower bound (size m).
         * @param lowerBound is the lower bound constraint.
         * @return true/false in case of success/failure.
         */
        template<int m>
        bool setLowerBound(Eigen::Matrix<c_float, m, 1>& lowerBound);

        /**
         * Set the array for upper bound (size m).
         * @param upperBound is the upper bound constraint.
         * @return true/false in case of success/failure.
         */
        template<int m>
        bool setUpperBound(Eigen::Matrix<c_float, m, 1>& upperBound);

        /**
         * Get the OSQPData struct.
         * @return a const point to the OSQPData struct.
         */
        OSQPData *const & getOptimizatorData() const;

        /**
         * Verify if all the matrix and vectors are already set.
         * @return true if all the OSQPData struct are set.
         */
        bool isSet() const;
    };
}

#include "OptimizatorData.tpp"

#endif