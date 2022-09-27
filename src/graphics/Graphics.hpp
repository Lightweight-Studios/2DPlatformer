#pragma once

namespace Graphics
{
   // @warning Throws on failure
   void initialize();

   // @note A symmetrical call to teardown should be made if a call to initialize was made
   void teardown();

} // namespace Graphics