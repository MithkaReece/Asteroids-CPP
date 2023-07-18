#pragma once

namespace Component
{
  /**
   * @brief WrapperBoundary component represents the boundary to be wrapped
   *
   *  It stores the boundary size which is the distance out from the window.
   *  Objects that cross this boundary are teleport to the otherside of the
   *  boundary (wrapping them within the boundary)
   */
  struct WrapperBoundary
  {
    float boundarySize;
  };
}