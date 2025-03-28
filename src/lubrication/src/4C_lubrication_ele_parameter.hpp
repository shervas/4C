// This file is part of 4C multiphysics licensed under the
// GNU Lesser General Public License v3.0 or later.
//
// See the LICENSE.md file in the top-level for license information.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef FOUR_C_LUBRICATION_ELE_PARAMETER_HPP
#define FOUR_C_LUBRICATION_ELE_PARAMETER_HPP

#include "4C_config.hpp"

#include <Teuchos_StandardParameterEntryValidators.hpp>

FOUR_C_NAMESPACE_OPEN

namespace Discret
{
  namespace Elements
  {
    /// Evaluation of general parameters (constant over time)
    class LubricationEleParameter
    {
     public:
      //! singleton access method
      static LubricationEleParameter* instance(
          const std::string& disname  //!< name of discretization
      );

      //! set parameters
      void set_time_parameters(Teuchos::ParameterList& parameters  //!< parameter list
      );

      //! set parameters
      void set_general_parameters(Teuchos::ParameterList& parameters  //!< parameter list
      );

      double time() const { return time_; };

      /// return function for the modified reynolds equation flag
      bool modified_reynolds() const { return modified_reynolds_; };
      /// return function for the Add squeeze term in reynolds equ. flag
      bool add_sqz() const { return addsqz_; };
      /// return function for the pure lubrication reynolds equ. flag
      bool pure_lub() const { return purelub_; };
      /// return function for surface roughness value in modified reynolds equ.
      double roughness_deviation() const { return roughness_deviation_; };

     private:
      //! private constructor for singletons
      LubricationEleParameter(const std::string& disname  //!< name of discretization
      );

      double time_;
      /// modified reynolds equation flag
      bool modified_reynolds_;
      /// Add squeeze term in reynolds equ. flag
      bool addsqz_;
      /// pure lubrication reynolds equ. flag
      bool purelub_;
      /// surface roughness STD value in modified reynolds equ.
      double roughness_deviation_;

    };  // class LubricationEleParameter
  }  // namespace Elements
}  // namespace Discret



FOUR_C_NAMESPACE_CLOSE

#endif
