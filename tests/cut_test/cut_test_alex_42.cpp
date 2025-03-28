// This file is part of 4C multiphysics licensed under the
// GNU Lesser General Public License v3.0 or later.
//
// See the LICENSE.md file in the top-level for license information.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "4C_cut_meshintersection.hpp"
#include "4C_cut_options.hpp"
#include "4C_cut_side.hpp"
#include "4C_cut_tetmeshintersection.hpp"
#include "4C_cut_volumecell.hpp"
#include "4C_fem_general_utils_local_connectivity_matrices.hpp"

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "cut_test_utils.hpp"

void test_alex42()
{
  Cut::MeshIntersection intersection;
  intersection.get_options().init_for_cuttests();  // use full cln
  std::vector<int> nids;

  int sidecount = 0;
  {
    Core::LinAlg::SerialDenseMatrix tri3_xyze(3, 3);

    tri3_xyze(0, 0) = 9.792e-01;
    tri3_xyze(1, 0) = 2.604e-01;
    tri3_xyze(2, 0) = -1.000e-04;
    tri3_xyze(0, 1) = 9.906e-01;
    tri3_xyze(1, 1) = 2.897e-01;
    tri3_xyze(2, 1) = -1.000e-04;
    tri3_xyze(0, 2) = 9.849e-01;
    tri3_xyze(1, 2) = 2.750e-01;
    tri3_xyze(2, 2) = 1.593e-02;
    nids.clear();
    nids.push_back(494);
    nids.push_back(498);
    nids.push_back(716);
    intersection.add_cut_side(++sidecount, nids, tri3_xyze, Core::FE::CellType::tri3);
  }
  {
    Core::LinAlg::SerialDenseMatrix tri3_xyze(3, 3);

    tri3_xyze(0, 0) = 9.906e-01;
    tri3_xyze(1, 0) = 2.897e-01;
    tri3_xyze(2, 0) = -1.000e-04;
    tri3_xyze(0, 1) = 9.906e-01;
    tri3_xyze(1, 1) = 2.896e-01;
    tri3_xyze(2, 1) = 3.196e-02;
    tri3_xyze(0, 2) = 9.849e-01;
    tri3_xyze(1, 2) = 2.750e-01;
    tri3_xyze(2, 2) = 1.593e-02;
    nids.clear();
    nids.push_back(498);
    nids.push_back(714);
    nids.push_back(716);
    intersection.add_cut_side(++sidecount, nids, tri3_xyze, Core::FE::CellType::tri3);
  }
  {
    Core::LinAlg::SerialDenseMatrix tri3_xyze(3, 3);

    tri3_xyze(0, 0) = 9.906e-01;
    tri3_xyze(1, 0) = 2.896e-01;
    tri3_xyze(2, 0) = 3.196e-02;
    tri3_xyze(0, 1) = 9.792e-01;
    tri3_xyze(1, 1) = 2.603e-01;
    tri3_xyze(2, 1) = 3.196e-02;
    tri3_xyze(0, 2) = 9.849e-01;
    tri3_xyze(1, 2) = 2.750e-01;
    tri3_xyze(2, 2) = 1.593e-02;
    nids.clear();
    nids.push_back(714);
    nids.push_back(695);
    nids.push_back(716);
    intersection.add_cut_side(++sidecount, nids, tri3_xyze, Core::FE::CellType::tri3);
  }
  {
    Core::LinAlg::SerialDenseMatrix tri3_xyze(3, 3);

    tri3_xyze(0, 0) = 9.792e-01;
    tri3_xyze(1, 0) = 2.603e-01;
    tri3_xyze(2, 0) = 3.196e-02;
    tri3_xyze(0, 1) = 9.792e-01;
    tri3_xyze(1, 1) = 2.604e-01;
    tri3_xyze(2, 1) = -1.000e-04;
    tri3_xyze(0, 2) = 9.849e-01;
    tri3_xyze(1, 2) = 2.750e-01;
    tri3_xyze(2, 2) = 1.593e-02;
    nids.clear();
    nids.push_back(695);
    nids.push_back(494);
    nids.push_back(716);
    intersection.add_cut_side(++sidecount, nids, tri3_xyze, Core::FE::CellType::tri3);
  }
  {
    Core::LinAlg::SerialDenseMatrix tri3_xyze(3, 3);

    tri3_xyze(0, 0) = 9.906e-01;
    tri3_xyze(1, 0) = 2.896e-01;
    tri3_xyze(2, 0) = 3.196e-02;
    tri3_xyze(0, 1) = 9.906e-01;
    tri3_xyze(1, 1) = 2.897e-01;
    tri3_xyze(2, 1) = -1.000e-04;
    tri3_xyze(0, 2) = 9.964e-01;
    tri3_xyze(1, 2) = 3.044e-01;
    tri3_xyze(2, 2) = 1.593e-02;
    nids.clear();
    nids.push_back(714);
    nids.push_back(498);
    nids.push_back(735);
    intersection.add_cut_side(++sidecount, nids, tri3_xyze, Core::FE::CellType::tri3);
  }
  {
    Core::LinAlg::SerialDenseMatrix tri3_xyze(3, 3);

    tri3_xyze(0, 0) = 1.002e+00;
    tri3_xyze(1, 0) = 3.190e-01;
    tri3_xyze(2, 0) = 3.195e-02;
    tri3_xyze(0, 1) = 9.906e-01;
    tri3_xyze(1, 1) = 2.896e-01;
    tri3_xyze(2, 1) = 3.196e-02;
    tri3_xyze(0, 2) = 9.964e-01;
    tri3_xyze(1, 2) = 3.044e-01;
    tri3_xyze(2, 2) = 1.593e-02;
    nids.clear();
    nids.push_back(733);
    nids.push_back(714);
    nids.push_back(735);
    intersection.add_cut_side(++sidecount, nids, tri3_xyze, Core::FE::CellType::tri3);
  }
  {
    Core::LinAlg::SerialDenseMatrix tri3_xyze(3, 3);

    tri3_xyze(0, 0) = 9.906e-01;
    tri3_xyze(1, 0) = 2.897e-01;
    tri3_xyze(2, 0) = -1.000e-04;
    tri3_xyze(0, 1) = 1.002e+00;
    tri3_xyze(1, 1) = 3.191e-01;
    tri3_xyze(2, 1) = -1.000e-04;
    tri3_xyze(0, 2) = 9.964e-01;
    tri3_xyze(1, 2) = 3.044e-01;
    tri3_xyze(2, 2) = 1.593e-02;
    nids.clear();
    nids.push_back(498);
    nids.push_back(502);
    nids.push_back(735);
    intersection.add_cut_side(++sidecount, nids, tri3_xyze, Core::FE::CellType::tri3);
  }
  Core::LinAlg::SerialDenseMatrix hex8_xyze(3, 8);

  hex8_xyze(0, 0) = 1.000e+00;
  hex8_xyze(1, 0) = 3.000e-01;
  hex8_xyze(2, 0) = 2.500e-02;
  hex8_xyze(0, 1) = 1.000e+00;
  hex8_xyze(1, 1) = 2.750e-01;
  hex8_xyze(2, 1) = 2.500e-02;
  hex8_xyze(0, 2) = 9.750e-01;
  hex8_xyze(1, 2) = 2.750e-01;
  hex8_xyze(2, 2) = 2.500e-02;
  hex8_xyze(0, 3) = 9.750e-01;
  hex8_xyze(1, 3) = 3.000e-01;
  hex8_xyze(2, 3) = 2.500e-02;
  hex8_xyze(0, 4) = 1.000e+00;
  hex8_xyze(1, 4) = 3.000e-01;
  hex8_xyze(2, 4) = 0.000e+00;
  hex8_xyze(0, 5) = 1.000e+00;
  hex8_xyze(1, 5) = 2.750e-01;
  hex8_xyze(2, 5) = 0.000e+00;
  hex8_xyze(0, 6) = 9.750e-01;
  hex8_xyze(1, 6) = 2.750e-01;
  hex8_xyze(2, 6) = 0.000e+00;
  hex8_xyze(0, 7) = 9.750e-01;
  hex8_xyze(1, 7) = 3.000e-01;
  hex8_xyze(2, 7) = 0.000e+00;

  nids.clear();
  for (int i = 0; i < 8; ++i) nids.push_back(i);

  intersection.add_element(1, nids, hex8_xyze, Core::FE::CellType::hex8);

  intersection.cut_test_cut(true, Cut::VCellGaussPts_DirectDivergence);
}
