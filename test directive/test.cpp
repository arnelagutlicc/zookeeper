// Filter will remove bbrsType combinations that have too many bbrs instances

bbrsCombRepoDataViewPtr_t MaxNumOfBbrsInstancesFilter::filter(bbrsCombRepoDataViewPtr_t sourceView) const
{
  std::vector<std::uint32_t> selectedIndexes;

  for (auto index : *(sourceView))
  {
    const auto& bbCapacitiesGroup = sourceView->getItem(index);
    const auto& bbCapacitiesList = bbCapacitiesGroup->bbCapacitiesList;
    bool selectIndex = true;

    //{[<bbrsBaseTypeName, maxNumOfBbrsInstances>], <counter>}
    std::map<std::tuple<std::string, std::uint32_t>, std::uint32_t> baseTypeNameCounter;

    for (const auto& bbCapacityItem : bbCapacitiesList)
    {
      for (const auto& bbrsType : bbCapacityItem.bbrsTypes)
      {
        if (const auto maxNumOfBbrsInstances = bbrsType->getMaxNumOfBbrsInstances())
        {
          if (maxNumOfBbrsInstances.value() == 0)
          {
            BRM_TRACE_ABNORMAL(AIS_STR("Unexpected maxNumOfBbrsInstances value (0) in bbrsType (%s).", bbrsType->getBaseTypeName().c_str()));
          }

          baseTypeNameCounter[{bbrsType->getBaseTypeName(), maxNumOfBbrsInstances.value()}]++;

          if (baseTypeNameCounter[{bbrsType->getBaseTypeName(), maxNumOfBbrsInstances.value()}] > maxNumOfBbrsInstances.value())
          {
            selectIndex = false;
            break;
          }
        }
      }

      if (!selectIndex)
      {
        break;
      }
    }

     for (const auto& bbCapacityItem : bbCapacitiesList)
    {
      for (const auto& bbrsType : bbCapacityItem.bbrsTypes)
      {
        if (const auto maxNumOfBbrsInstances = bbrsType->getMaxNumOfBbrsInstances())
        {
          if (maxNumOfBbrsInstances.value() == 0)
          {
            BRM_TRACE_ABNORMAL(AIS_STR("Unexpected maxNumOfBbrsInstances value (0) in bbrsType (%s).", bbrsType->getBaseTypeName().c_str()));
          }

          baseTypeNameCounter[{bbrsType->getBaseTypeName(), maxNumOfBbrsInstances.value()}]++;

          if (baseTypeNameCounter[{bbrsType->getBaseTypeName(), maxNumOfBbrsInstances.value()}] > maxNumOfBbrsInstances.value())
          {
            selectIndex = false;
            break;
          }
        }
      }

      if (!selectIndex)
      {
        break;
      }
    }

     for (const auto& bbCapacityItem : bbCapacitiesList)
    {
      for (const auto& bbrsType : bbCapacityItem.bbrsTypes)
      {
        if (const auto maxNumOfBbrsInstances = bbrsType->getMaxNumOfBbrsInstances())
        {
          if (maxNumOfBbrsInstances.value() == 0)
          {
            BRM_TRACE_ABNORMAL(AIS_STR("Unexpected maxNumOfBbrsInstances value (0) in bbrsType (%s).", bbrsType->getBaseTypeName().c_str()));
          }

          baseTypeNameCounter[{bbrsType->getBaseTypeName(), maxNumOfBbrsInstances.value()}]++;

          if (baseTypeNameCounter[{bbrsType->getBaseTypeName(), maxNumOfBbrsInstances.value()}] > maxNumOfBbrsInstances.value())
          {
            selectIndex = false;
            break;
          }
        }
      }

      if (!selectIndex)
      {
        break;
      }
    }

     for (const auto& bbCapacityItem : bbCapacitiesList)
    {
      for (const auto& bbrsType : bbCapacityItem.bbrsTypes)
      {
        if (const auto maxNumOfBbrsInstances = bbrsType->getMaxNumOfBbrsInstances())
        {
          if (maxNumOfBbrsInstances.value() == 0)
          {
            BRM_TRACE_ABNORMAL(AIS_STR("Unexpected maxNumOfBbrsInstances value (0) in bbrsType (%s).", bbrsType->getBaseTypeName().c_str()));
          }

          baseTypeNameCounter[{bbrsType->getBaseTypeName(), maxNumOfBbrsInstances.value()}]++;

          if (baseTypeNameCounter[{bbrsType->getBaseTypeName(), maxNumOfBbrsInstances.value()}] > maxNumOfBbrsInstances.value())
          {
            selectIndex = false;
            break;
          }
        }
      }

      if (!selectIndex)
      {
        break;
      }
    }

    if (selectIndex)
    {
      selectedIndexes.push_back(index);
    }
  }

  if (selectedIndexes.empty())
  {
    return nullptr;
  }

  return std::make_shared<bbrsCombinationRepoDataView_t>(sourceView->getDataSet(), selectedIndexes);
}
